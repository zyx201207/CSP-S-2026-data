#include<bits/stdc++.h>
using namespace std;
int c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		long long a1,a2,a3,b;
		cin>>b;
		for(int i=2;i<=n;i++){
			a1=a2,a2=a3;
			cin>>a3;
			if(i>=4&&a2-b<=d&&a3-b>d&&i<n){
				cout<<n-i+1<<endl;
				return 0;
			}
		}
		/*int ans=0;
		for(int i=1;i<=n,i+3<=n;i++){
			if(d>=a[i+2]-a[i]&&d<a[i+3]-a[i]){
				ans++;
			}
		}
		cout<<ans<<endl;*/
		cout<<0<<endl;
	}
}
