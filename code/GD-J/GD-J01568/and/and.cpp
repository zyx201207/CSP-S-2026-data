#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=200005;
int n,m,ans=-1e18,a[MAXN],maxx; 
void dfs(int x,int p,int k){
	if(x==m){
		ans=max(ans,k);
		return;
	}
	for(int i=p+1;i<=n;i++){
		dfs(x+1,p+1,k|a[i]);
		dfs(x,p+1,k);
	}
} 
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i],maxx=max(maxx,a[i]);
	if(m==2){
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				ans=max(ans,a[i]|a[j]);
	}
	if(m==n){
		ans=a[1];
		for(int i=1;i<=n;i++)
			ans=ans|a[i];
	}
	if(m==n-1){
		int sum=a[1];
		for(int i=1;i<=n;i++){
			if(i==1)
				sum=a[2];
			else
				sum=a[1];
			for(int j=1;j<=n;j++){
				if(j!=i)
					sum|=a[i];
			}
			ans=max(ans,sum);
		}
	}
	if(m==1)
		ans=maxx;
	if(n<=20){
		dfs(0,0,a[1]);
	}
	cout<<ans;
	return 0;
}
