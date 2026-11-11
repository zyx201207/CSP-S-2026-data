//贵阳市第三实验中学  刘家豪  GZ-S00432
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=501010;
int c,t;
int x[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		int ans=0;
		for(int i=1;i<=n-1;i++){
			int cnt=0;
			for(int j=i;j<=n;j++){
				
				for(int k=i+1;k<=j-1;k++){
					if(x[k]-x[i]<=d&&x[j]-x[k]<=d){
						cnt++;
					}
				}
				
			}if(cnt>1)ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
