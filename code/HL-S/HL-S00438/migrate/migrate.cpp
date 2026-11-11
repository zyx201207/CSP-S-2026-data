#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+10;
ll c,r,n,d,a[N],ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> r;
	for(int i=1;i<=r;i++){
		ans=0;
		cin >> n >> d;
		for(int i=1;i<=n;i++) cin >> a[i];
		for(int i=1;i<=n;i++){
			if(a[i]<=2*d-1) continue;
			int k=lower_bound(a+1,a+n+1,a[i]-2*d+1)-a;
			if(a[k]==a[i]-2*d+1) ans++;
		}
		cout << ans << endl;
	}
	return 0;
}