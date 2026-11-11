#include<stdio.h>
#define N 200001
#define ll long long
int c,t,n,d,ds,s,tp,ans;
ll p[N],chsp[N];
int dis(int x,int y){
	int s=0;
	ll lst=x;
	for(int i=x+1;i<=y;++i){
		if(p[i]-p[lst]>d)return -1;
		if(i==y)return s+1;
		if(p[i+1]-p[lst]>d)lst=i,++s;
	}
	return -1;
}
void dfs(int l,int r){
	if(l>r){
		if(tp+1==ds){
			chsp[++tp]=r+1;
			for(int i=2;i<=tp;++i)
				if(chsp[i]-chsp[i-1]>d)return;
			++s;
		}
		return;
	}
	chsp[++tp]=p[l];
	dfs(l+1,r);
	--tp;
	dfs(l+1,r);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%d",&n,&d);
		for(int i=1;i<=n;++i)scanf("%lld",p+i);
		for(int i=1;i<=n;++i){
			chsp[1]=p[i],tp=1;
			for(int j=i+1;j<=n;++j){
				s=0;
				ds=dis(i,j);
				if(ds!=-1){
					dfs(i+1,j-1);
					if(s==2)++ans;
				}
			}
		}
		printf("%d\n",ans);
		ans=0;
	}
	return 0;
/*	
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
}
