#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n,m,a[N],maxai=-1e18,ansn,ans=-1e18,ansd;
void dfs(int now,int num,int asum){
	if(now==n+1){
		if(num==m)ans=max(ans,asum);	
		return;
	}
	dfs(now+1,num+1,asum&a[now]);
	dfs(now+1,num,asum);
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	ansn=ansd=2147483647;
	for(int i=1;i<=n;++i)cin>>a[i],maxai=max(maxai,a[i]),ansn=ansn&a[i];
	if(n>2000){
		sort(a+1,a+1+n);
		for(int i=n;i>=n-m+1;--i){
			ansd=ansd&a[i];
		}
		cout<<ansd;
		return 0;
	}
	if(m==1){
		cout<<maxai;
		return 0;
	}
	if(m==2){
		int pr=-1e18;
		for(int i=1;i<=n;++i){
			for(int j=i+1;j<=n;++j){
				pr=max(pr,a[i]&a[j]);
			}
		}
		cout<<pr;
		return 0;
	}
	if(m==n){
		cout<<ansn;
		return 0;
	}
	if(n<=20){
		dfs(1,0,2147483647);
		cout<<ans;
	}
	return 0;
}
