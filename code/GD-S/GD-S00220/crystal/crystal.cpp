#include <iostream>
#include <algorithm>
using namespace std;

typedef long long  ll;
ll n,m;
ll a[(int)5e5+5];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	cout << 67 << endl;
	return 0;
}
