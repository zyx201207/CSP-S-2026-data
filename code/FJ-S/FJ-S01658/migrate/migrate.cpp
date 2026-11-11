#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long
const int N=2e6+5;
int c,t,ans;
int n,d,a[N],dp[N];
#undef int
int main(){
	#define int long long
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--){
		ans=0;
		cin >> n >> d;
		bool pd=true;
		for(int i=1;i<=n;i++){
			cin >> a[i];
			if(i>1 && a[i]-a[i-1]!=a[i-1]-a[i-2]) pd=false;
		}
		if(pd){
			if(d<a[2]-a[1]||d>a[3]-a[1]){
				cout << "0\n";
			}else{
				cout << n-2 << "\n";
			}
		}else{
		
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dp[i]=0;
			}
			dp[i]=1;
			for(int j=i;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					if(a[k]-a[j]<=d){
						dp[k]+=dp[j];
					}else{
						break;
					}
				}
			}
			for(int j=i;j<=n;j++){
//				cout << i << " " << j <<" " << dp[j]<< "\n";
				if(dp[j]==2){
					ans++;
				}
			}
		}
		cout << ans << "\n";
	}
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

*/
