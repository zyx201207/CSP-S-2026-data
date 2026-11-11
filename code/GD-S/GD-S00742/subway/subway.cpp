#include<bits/stdc++.h>
using namespace std;typedef long long ll;
const int M=5e5+5,N=505,Q=1e5+5;
int i,j,m,n,q,qt,x,y,c,d;
int w[M],k[N],xt[Q],yt[Q],u[M];
ll as=1e17;
vector <int> a[N],t[N],sw[M];
void dfs(int s,ll tm,int o){//当前所在点,所花的时间,几号线
	if(tm>=as) return;
	if(s==y){
		int xia;
		if(o==0) xia=0;
		else xia=t[o][y-1];
		as=tm+xia+w[s];
	}else{
		int sz=sw[s].size(),i,j;
		for(i=0;i<sz;i++){
			int x=sw[s][i],xia;
			for(j=0;j<a[x].size();j++){//换乘至x号线
				if(u[a[x][j]]) continue;
				u[a[x][j]]=1;
				if(o==0) xia=0;
				else xia=t[o][s];
				dfs(a[x][j],tm+xia+t[x][s-1],x);
				u[a[x][j]]=0;
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&qt);
	for(i=1;i<=m;i++){
		scanf("%d",w+i);
	}for(i=1;i<=n;i++){
		scanf("%d",k+i);
		for(j=1;j<=k[i];j++){
			scanf("%d%d",&x,&y);
			a[i].push_back(x);
			t[i].push_back(y);
			sw[x].push_back(i);
		}
	}for(i=1;i<=qt;i++){
		scanf("%d%d",xt+i,yt+i);
	}
	for(q=1;q<=qt;q++){
		as=1e17;
		x=xt[q],y=yt[q];
		u[x]=1;
		dfs(x,w[x],0);
		printf("%lld\n",as);
		u[x]=0;
	}
	return 0;
}
