#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6+5;
const int inf = 1e18+1;
int n,d,x[N];

bool f(int a,int y){
	return abs(x[y] - x[a]) <= d;
}
int sol(){
	cin>>n>>d;
	for(int i = 1; i <= n; i++) cin >> x[i];
	
	
	return 0;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	int c,t;cin>>c>>t;
	while(t--)cout<<sol()<<"\n";
	return 0; 
} 
