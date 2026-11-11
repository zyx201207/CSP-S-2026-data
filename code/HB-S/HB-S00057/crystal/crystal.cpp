#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500010],f[500010];
int ans = -1e9;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
	    cin>>a[i];
	}
	sort(a + 1,a + n + 1);
	int l = 1;
	for(int r = 1;r <= n;r++){
		f[r] = f[r - 1] + (r - l) * 1ll * (a[r] - a[r - 1]);
		while(f[r] > m){
			f[r] -= (a[r] - a[l]);
			l++;
		}
		ans = max(ans,(r - l + 1));
	}
	cout<<ans;
    return 0;
}
