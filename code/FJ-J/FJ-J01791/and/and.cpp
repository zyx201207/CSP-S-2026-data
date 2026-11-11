#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct o{
	ll a,b,sum;
}a[200010];
bool cmp(o a,o b){
	if (a.b != b.b) return a.b > b.b;
	else return a.sum > b.sum;
}
ll n,m,ans;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (ll i=1;i<=n;i++){
		ll cnt=0,c=0;
		cin>>a[i].a;
		a[i].b = a[i].a;
		if ((a[i].b&1) == 1) cnt++;
		while(a[i].b > 0){
			if ((a[i].b>>1)&1 == 1) cnt++;
			a[i].b = a[i].b>>1;
			c++;
		}
		a[i].b = cnt;
		a[i].sum = c;
	}
	sort(a+1,a+n+1,cmp);
	ans = a[1].a;
	for (ll i=1;i<=m;i++){
		ans = (ans&a[i].a);
	}
	cout<<ans;
	return 0;
}

