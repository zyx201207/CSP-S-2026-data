#include <bits/stdc++.h>
using namespace std;
const int maxn=2e6+5;
typedef long long ll;
struct dta{
	int p,id;
}land[maxn];
ll c,t,n,d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while (t--){
		cin >> n >> d;
		for (int i=1;i<=n;i++){
			cin >> land[i].p;
			land[i].id=i;
		}
		bool ch=1;
		ll tmp=land[2].p-land[1].p;
		for (int i=1;i<n;i++){
			if (land[i].p+tmp!=land[i+1].p){
				ch=0;
				break;
			}
		}
		if (ch)
			cout << 0 << '\n';
		else
			cout << 1 << '\n';	 
	}
	return 0;
}
