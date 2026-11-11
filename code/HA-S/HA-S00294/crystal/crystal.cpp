#include<iostream>
#include<algorithm>
using namespace std;
long long n,m;
long long a[500010];
int l = 1,r = 1;
//int maxl,maxr;
long long u = 1,nu = 0;
long long ans = 0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a + 1,a + 1 + n);
	for(;r <= n;){
		r++;
		nu += ((a[r] - a[r - 1]) * u);
		u++;
		if(nu > m){
			while(nu > m){
				nu -= (a[r] - a[l]);
				l++;
				u--;
			}
		}
		if(u > ans){
			ans = u;
			// maxl = l;
			// maxr = r;
		}
		if(r == n){
			break;
		}
	}
	cout << ans;
	
	return 0;
}
