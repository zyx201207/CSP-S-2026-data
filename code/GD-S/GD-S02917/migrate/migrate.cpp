#include <bits/stdc++.h>
using namespace std;
long long n,a[100005],t,d,c;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while (t--){
		cin>>n>>d;
		for (int i=1;i<=n;i++){
			cin>>a[i];
		}	
		long long ans=0;
		for (int i=1;i<=n-3;i++){
			for (int j=i+3;j<=n;j++){
				if (a[j]-a[i]>d && a[j]-a[i]<2*d){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
