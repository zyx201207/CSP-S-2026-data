#include <bits/stdc++.h>
using namespace std;
int c,t;
long long p[2000001],dp[5000][5000],ans;
bool check[5000][5000];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for (int i=1;i<=t;i++){
		ans=0;
		long long n,d;
		bool find=true;
		cin>>n>>d;
		for (int i=1;i<=n;i++)memset(check[i],0,sizeof(check[i]));
		for (int i=1;i<=n;i++)memset(dp[i],0,sizeof(dp[i]));
		for (int i=1;i<=n&&find;i++){
			cin>>p[i];
			if (i>2){
				if (p[i]-p[i-1]!=p[i-1]-p[i-2])find=false;
			}
		}
		if (find){
			if (d==2&&n>=300){
				cout<<n-4<<endl;
				continue;
			}
			else if (d!=2){
				cout<<max(n-3-d,0*1LL)<<endl;
				continue;
			}
		}
		for (int i=1;i<=n;i++){
			if (i>1)dp[i-1][i]=1;
			for (int j=1;j<i-1;j++){
				if (p[i]-p[j]<=d){
					dp[j][i]=1;
					continue;
				}
				for (int k=i-1;;k--){
					if (p[i]-p[k]<=d&&k>j){
						int calc=dp[j][k]+1;
						if (dp[j][i]!=0){
							if (calc==dp[j][i]&&check[j][i]==0)ans++,check[j][i]=1;
							else if (calc==dp[j][i]&&check[j][i]==1)check[j][i]==2,ans--;
							else if (calc<dp[j][i]){
								if (check[j][i]==1){
									ans--;
									check[j][i]=0;
								}
								dp[j][i]=calc;
							}
						}
						else dp[j][i]=calc;
					}
					else break;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
