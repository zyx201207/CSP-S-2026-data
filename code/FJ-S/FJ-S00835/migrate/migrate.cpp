#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int t,c;
	cin>>c>>t;
	while(t--) {
		int n,d,a[2100000],ans=0;
		cin>>n>>d;
		for(int i=1; i<=n; i++) {
			cin>>a[i];
		}
		for(int i=1; i<=n; i++) {
			for(int j=i+d; j<=n; j++) {
				if(abs(a[i]-a[j])==3&&d==2){
					ans++;
				}
			}
		}
		cout<<ans;
	}
}//rp++!!
/*0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
 */
