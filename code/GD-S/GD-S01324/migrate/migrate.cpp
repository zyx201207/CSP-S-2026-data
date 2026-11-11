#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long a[2000010],d,f[2000010],dp[2000010],bf[2000010],ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=0;i<=n+1;i++){
			f[i]=0;
			dp[i]=0;
			bf[i]=0;
		}
		for(int i=1;i<=n;i++){
			int l=i,r=i;
			dp[i]=bf[i]=1;
			for(int j=i-1;j>=1;j--){
				f[j]=0;
				dp[j]=bf[j]=0;
				while(a[r]-a[j]>d&&r>j)r--;
				if(r==j)break;
				l=min(l,r);
				while(f[l]==f[r]&&l>j)l--;
				dp[j]=bf[l+1]-bf[r+1];
				bf[j]=bf[j+1]+dp[j];
				if(dp[j]==2){
					ans++;
				}
				f[j]=f[r]+1;
			}
		}
		cout<<ans<<'\n';
	}
	cout<<flush;
	return 0;
}
