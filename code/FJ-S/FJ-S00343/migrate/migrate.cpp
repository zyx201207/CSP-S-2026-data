#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
int c,T,n,d,a[N];
bool flag=0;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(0),cout.tie(0);
	cin >> c >> T;
	while(T--){
		flag=0;
		cin >> n >> d;
		for(int i=1;i<=n;i++){
			cin >> a[i];
			if(i>=3 && a[i]-a[i-1]!=a[i-1]-a[i-2]){
				flag=1;
			}
		}
		if(flag==0){
			if(d<a[2]-a[1]){
				cout << 0 << endl;;
				continue;
			}
			d=(d-(d%(a[2]-a[1])))/(a[2]-a[1]);
			if(d==1){
				cout << 0 << endl;
				continue;
			}
			if(d+d-1>n){
				cout << 0 << endl;
				continue;
			}
			cout << n-(d+d)+1 << endl;
			continue;
		}
	}
	return 0;
}
