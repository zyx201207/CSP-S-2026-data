#include<bits/stdc++.h>
using namespace std;
const int M=2*1e6+10;
int a[M];
int n;
double d;
int c,t;
int ans = 0;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	for(int i=1;i<=t;i++){
		cin >> n >> d;
		memset(a,0,sizeof(a));
		for(int j=1;i<=n;i++){
			cin >> a[i];
		}
		int m = a[2]-a[1];
		for(int j=1;i<=n;i++){
			a[i]/=m;
		}
		if(d<=m){
			cout << 0 << endl;
			continue;
		}
		else{
			for(int j=1;j<=n;j+=2){
				ans += n/j;
			}
			cout << ans << endl;
		}
	}
	return 0;
} 
