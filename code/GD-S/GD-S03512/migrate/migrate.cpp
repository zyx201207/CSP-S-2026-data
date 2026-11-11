#include <bits/stdc++.h>
using namespace std;
const int N=2e6+10;
vector <int> v[N];
int c,t,n,d,a[N],cnt;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while (t--){
		cin>>n>>d;
		for (int i=1;i<=n;i++){
			cin>>a[i];
		}
		for (int i=1;i<=n;i++){
			for (int j=i+1;j<=i+d;j++){
				if (abs(a[i]-a[j])<=d){
					v[i].push_back(a[j]);
				}
			}
		}
		cnt=a[2]-a[1];
		if (cnt>=d) cout<<0;
		else cout<<n/(2+d/cnt)+n%(2+d/cnt);
		for (int i=1;i<=n;i++){
			v[i].erase(v[i].begin(),v[i].end());
		}
	}
	return 0;
}
