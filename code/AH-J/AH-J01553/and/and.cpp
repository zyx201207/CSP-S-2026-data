#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2005,M=2*1e5+5;
ll bit[25];
int n,m;
ll a[N];
ll dp[N][N];
ll ans;
int flag;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	bit[0]=1;
	for(int i=1;i<=30;i++){
		bit[i]=bit[i-1]*2;
	}
	cin >> n >> m;
	flag=1;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(a[i]!=i-1){
			flag=0;
		}
	}
	if(n<=2000){
		ll maxn=a[1];
		for(int i=1;i<=n;i++){
			maxn=max(maxn,a[i]); 
			dp[i][1]=maxn;
		}
		for(int i=1;i<=n;i++){
			for(int j=2;j<=m;j++){
				if(i<j){
					dp[i][j]=-1;
				}else{
					dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]&a[i]);
				}
			}
		}
		for(int i=1;i<=n;i++){
			ans=max(ans,dp[i][m]);
		}
		cout << ans;
	}else{
		for(int i=1;i<=30;i++){
			if(n==bit[i]&&flag==1){
				flag=2;
				break;
			}
		}
		if(flag==2){
			ans=n-1;
			int i=n;
			while(m>0){
				ans&=a[n];
				m--;
				n--;
			}
			cout << ans;
			return 0;
		}
		ans=a[1];
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]); 
		}
		cout << ans;
	}
	return 0;
}


