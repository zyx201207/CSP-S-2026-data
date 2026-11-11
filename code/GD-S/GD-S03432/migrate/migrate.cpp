#include <bits/stdc++.h>
#define int long long 
using namespace std;
int n,m,k,s,t,c,d,q,x[500005];
struct node {
	int s,sum;	//飞的次数和路径数量 
}f[5000][5000];

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >>c >> t;
	//默认x等差 
	while(t--){
		cin >> n >> d;
		
		if(n == 1){
			cout << 0;continue;
		}
		for(int i =1;i<=n;i++){
			cin >> x[i];
		}
		if(x[2]-x[1]>d){
			cout << 0;continue;
		}
		int o = d/(x[2]-x[1]);//一次能飞最多几个岛
		if(o == 1){
			cout << 0;continue;
		} 
		o = o*2-1;
		int ans = n-o;
		
		cout << ans<<"\n";
		 
	}
	return 0;
}
