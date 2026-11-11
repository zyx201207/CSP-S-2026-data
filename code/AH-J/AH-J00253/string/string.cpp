#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
const int N=1e6+5;
const int mod=1e9+7;
const int inf=2e9;
int n;
ll ans,sum;
struct aa{
	ll s;
	char c;
}a[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i].s >> a[i].c;
		sum+=a[i].s;
	}
	int l=1,r=n;
	while(l<r){
		if(a[l].s<a[r].s){
			if(a[l].c!=a[r].c) ans+=a[l].s;
			a[r].s-=a[l].s;
			l++;
		}
		else{
			if(a[l].c!=a[r].c) ans+=a[r].s;
			a[l].s-=a[r].s;
			r--;
		}
	}
	cout << ans;
	return 0;
}


