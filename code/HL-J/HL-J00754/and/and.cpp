#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[200005];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m,n;cin >> n >> m;
	for(int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
	}
	ll mx = -1;
	if(m == 1){
		for(int i = 1;i <= n;i++){
			mx = max(mx,a[i]);
		}
		cout << mx;
	}
	else if(m == 2){
		for(int i = 1;i <= n;i++){
			for(int j = i+1;j <= n;j++){
				mx = max(a[i],a[j]);
			}
		}
		cout << mx;
	}
	else{
		for(int i = 1;i <= n;i++){
			mx &= a[i];
		}
		cout << mx;
	}
	return 0;
}