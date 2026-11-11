#include<bits/stdc++.h>
using namespace std;
const int N=200010;
typedef long long ll;
#define endl '\n'

struct info{
	ll x;
	char c;
}a[N];

ll n;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n;
	ll s=0;
	for (int i=1;i<=n;i++)
		cin >> a[i].x >> a[i].c,s+=a[i].x;
	char now=a[1].c;
	ll ans=0,l=a[1].x,r=0,c1=2,c2=n;
	while (c1<=c2){
		if (l>r){
			r+=a[c2].x;
			if (l<r){
				if (now!=a[c2].c)
					ans+=l,now=a[c2].c;
				r-=l,l=0;
			}
			else{
				if (now!=a[c2].c)
					ans+=r;
				l-=r,r=0;
			}
			c2--;
		}
		else{
			l+=a[c1].x;
			if (l<r){
				if (now!=a[c1].c)
					ans+=l;
				r-=l,l=0;
			}
			else{
				if (now!=a[c1].c)
					ans+=r,now=a[c1].c;
				l-=r,r=0;
			}
			c1++;
		}
	}
	cout << ans << '\n';
	return 0;
}

