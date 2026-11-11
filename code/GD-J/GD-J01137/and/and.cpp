#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,ans,m,a[100010],b[100010];
void dfs(int t,int p){
	if(t>m){
		int sum=b[1];
		for(int i=2;i<=m;i++)
			sum=(sum&b[i]);
		ans=max(ans,sum);
		return;
	}
	if(p>n) return;
	b[t]=a[p];
	dfs(t+1,p+1);
	b[t]=0;
	dfs(t,p+1);
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(n<=2000&&n>20){
		if(m==n){
			ans=a[1];
			for(int i=2;i<=n;i++)
				ans=(ans&a[i]);
			cout<<ans;
		}
		else if(m==1){
			for(int i=1;i<=n;i++)
				ans=max(ans,a[i]);
			cout<<ans;
		}
		else if(m==2){
			for(int i=1;i<=n;i++)
				for(int j=i+1;j<=n;j++)
					ans=max(ans,(a[i]&a[j]));
			cout<<ans;
		}
	}
	else{
		dfs(1,1);
		cout<<ans;
	}
	return 0;
}
