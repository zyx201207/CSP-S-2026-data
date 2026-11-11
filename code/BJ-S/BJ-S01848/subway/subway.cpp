#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005],qx,qy,ans=0;
bool book[500005],bokl[500005];
vector<int>a[500005];
vector<int>t[500005];
vector<int>za[500005];
vector<int>zt[500005];
void egg(int x,int cosl,int le){
	if(x==qy and le==0){
		if(cosl<ans)ans=cosl;
		return;
	}
	if(za[x].size()>0 and le==1){
		int sizz=a[x].size();
		for(int i=0;i<sizz;i++){
			if(book[a[x][i]]==false){
				book[a[x][i]]=true;
				egg(a[x][i],cosl+t[x][i],0);
				book[a[x][i]]=false;
			}
		}
	}else if(a[x].size()>0 and le==0){
		int sizz=za[x].size();
		for(int i=0;i<sizz;i++){
			if(bokl[za[x][i]]==false){
				book[za[x][i]]=true;
				egg(za[x][i],cosl+zt[x][i],1);
				book[za[x][i]]=false;
			}
		}
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		long long k=0,ai,ti;
		scanf("%lld",&k);
		for(int j=1;j<=k;j++){
			scanf("%lld%lld",&ai,&ti);
			a[i].push_back(ai);
			t[i].push_back(ti);
			za[ai].push_back(i);
			zt[ai].push_back(ti);
		}
	}
	for(int i=1;i<=q;i++){
		scanf("%lld%lld",&qx,&qy);
		ans=10000000000000000;
		egg(qx,0,0);
		printf("%lld\n",ans+w[qx]+w[qy]);
	}
	return 0;
}
