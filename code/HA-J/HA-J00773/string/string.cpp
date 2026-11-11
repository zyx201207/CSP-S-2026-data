#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e5+5;
ll n,a[N],l,r,ans;
char c[N];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for (int i = 1;i <= n;i++) cin>>a[i]>>c[i];
	l = 1,r = n;
	while (l < r){
		ll num = min(a[l],a[r]);
		if (c[l] != c[r]) ans += num;
		a[l] -= num;
		a[r] -= num;
		if (!a[l]) l++;
		if (!a[r]) r--;
	}
	cout<<ans;
	return 0;
}
