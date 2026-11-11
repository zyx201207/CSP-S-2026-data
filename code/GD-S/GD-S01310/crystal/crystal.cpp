#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500005];
int d[500005];
int c[500005];
int ans;
int hm;
signed main(){
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	cin>> n>>m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			int k=0;
			for(int o=j;o<=i;o++){
				k+=a[i]-a[o];
			}
			if(k<=m){
				ans=max(ans,(i-j+1));
			}
		}
	}
	cout << ans;
	return 0;
}
