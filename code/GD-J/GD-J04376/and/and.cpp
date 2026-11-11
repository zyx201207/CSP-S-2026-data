#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,m;
int a[N];
int ma;
int x;
int ans;
void dfs(int now,int num,int mark){
	if(now>n-m+num+1) return;
	if(num==m){
//		printf("1\n");
		ans=max(ans,mark);
		return;
	}
//	printf("%lld %lld \n",now,num);
	for(int i=now+1;i<=n;i++){
		dfs(i,num+1,mark&a[i]);
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	x=(1ll<<31ll)-1ll;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ma=max(ma,a[i]);
		x=(x&a[i]);
	}
	if(m==1){
		printf("%lld",ma);
		return 0;
	}
	if(m==n){
		printf("%lld",x);
		return 0;
	}
	if(m==2){
//		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		printf("%lld",ans);
		return 0;
	}
	for(int i=1;i<=n-m+1;i++){
		dfs(i,1,a[i]);
	}
	printf("%lld",ans);
	return 0;
}
/*
5 3
31 3 1 15 7

*/
