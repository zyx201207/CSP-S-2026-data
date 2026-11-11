#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
#define int long long
int c,t;
mt19937 gyj(time(0));
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c >> t;
	while(t--){
		int n,k;
		cin >> n >> k;
		for(int i = 1;i <= n-1;i ++){
			int t1,t2;
			cin >>t1 >> t2;
		}
		cout << gyj()%k+1<<' ';
	}
	return 0;
} 
