#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
long long n,d,a[N],ans;
int main(){
//	freopen("migrate.in","r",stdin);
//	freopen("migrate.out","w",stdout);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		bool flagA=1;
		for(int i=1;i<=n;i++){
			cin >> a[i];
			if(a[i]-a[i-1]!=a[i-1]-a[i-2]&&i>2)flagA=0;
		}
		if(flagA){
			if(a[3]-a[1]<=d&&a[4]-a[1]>d)cout<<n-3<<"\n";
			else cout<<0<<"\n";
			continue;
		}
		ans=0;
		for(int i=1;i<n-1;i++){
			for(int j=i+2;j<=n;j++){
				if(a[j]-a[j-2]<=d){
					if(j==i+2)ans++;
					else if(a[j]-a[j-3]<=d)break;
					else ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	
	return 0;
} 
