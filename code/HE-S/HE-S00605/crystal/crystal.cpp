#include<bits/stdc++.h>
using namespace std;
#define mid ((l+r)>>1)
typedef long long ll;
const int N=5e5+10;
const ll inf=1e18;
int n;
ll m,a[N],ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++)cin >> a[i];
	sort(a+1,a+1+n);
	a[0]=a[1];
	ll use=0;
	for(int i=1;i<=n;i++){
		int w=a[i]-a[i-1];
		if(use+w*(i-1)<=m){
			use+=w*(i-1);
			ans++;
		}else break;
	}
	cout << ans;
	return 0;
}
