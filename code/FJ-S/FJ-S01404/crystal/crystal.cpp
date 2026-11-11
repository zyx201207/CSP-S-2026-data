#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
ll n,m;
ll cnt=0;
int a[N];
int main(){//»¬¶¯´°¿Ú 
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	int l=1,r=1;
	int mx=1;
	while(l<=r&&r<n){
		r++;
		ll num=(r-l)*(a[r]-a[r-1]);
		ll bb=cnt+num;
		while(bb>m&&l<=r){
			bb-=a[r+1]-a[l];
			++l;
		}
		cnt=bb;
		mx=max(mx,r-l+1);
	}
	cout << mx;
}
