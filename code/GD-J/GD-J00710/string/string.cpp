#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct sss{
	char zm;
	ll qd,zd;
} brr[200005];
ll l = 0,n;char c[200005];ll a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(ll i = 1;i<=n;++i){
		cin >> a[i] >> c[i];
	}
	ll sum = 0;ll zz1 = 1,zz2 = n;
	ll sy = 0;bool zz3 = 0;
	while(zz1 < zz2){
		if(c[zz1] != c[zz2]){
			sum+=min(a[zz1],a[zz2]);
		}
		sy += max(a[zz1],a[zz2]) - min(a[zz1],a[zz2]);
		if(a[zz1] >= a[zz2])
			while(sy > 0){
				if(c[zz1] != c[zz2]){
					sum+=a[zz2];
				}
				sy-=a[zz2];
				zz2--;
			}
		else
			while(sy > 0){
				if(c[zz1] != c[zz2]){
					sum+=a[zz1];
				}
				sy-=a[zz1];
				zz1++;
			}
			if(sy<=0)zz1++;
	}
	cout << sum;
	return 0;
}
