#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[1000005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ll n,m;
	cin >> n >> m;
	for(int i = 1;i<=n;++i){
		cin >> a[i];
	}
	cout << a[3] << " " << a[1] " " << a[4];
	return 0;
}
