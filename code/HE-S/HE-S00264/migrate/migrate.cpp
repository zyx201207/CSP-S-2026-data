#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t;
int a[2000010];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--){
		memset(a,0,sizeof(a));
		int n,d;
		cin >> n >> d;
		for(int i = 1;i<=n;i++){
			cin >> a[i];
		}
		int cha = a[2]-a[1];
		if(d < cha*2) cout << 0 << '\n';
		else{
			int js = d/cha;
			cout << n-js-1 << '\n';
		}
	}
	return 0;
} 
