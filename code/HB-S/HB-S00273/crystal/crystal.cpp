#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn=5e5+5;
int n,m;
int a[maxn];
int s[maxn];
int c[maxn];
int dp[maxn];
int ok;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	a[0]=0;
	
	sort(a+1,a+n+1);
	
	for(int i=1;i<n;i++){
		if(a[i]-a[i-1]==a[i+1]-a[i])
			ok=1;
		else ok=0;
	}
	
	if(ok==1){
		int cnt=0;
		int ans;
		for(int i=n-1;i;i--){
			cnt+=a[n]-a[i];
			if(cnt>m){
				ans=n-i;
				break;
			}
			if(cnt==m){
				ans=n-i+1;
				break;
			}
		}
		cout<<ans<<"\n";
	}
	else if(ok==0){
		for(int j=n;j>=1;j--){
			int cnt=0;
			for(int i=j-1;i;i--){
				cnt+=a[j]-a[i];
				if(cnt>m){
					c[j]=j-i;
					break;
				}
				if(cnt==m){
					c[j]=j-i+1;
					break;
				}
			}
			//cout<<c[j]<<" ";
			sort(c+1,c+n+1);
		}
		cout<<c[n]<<"\n";
	}
	return 0;
}
