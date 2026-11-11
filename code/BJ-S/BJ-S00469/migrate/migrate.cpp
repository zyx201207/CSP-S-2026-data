
#include <bits/stdc++.h>
#define int long long
#define f(i,a,b) for(int i=(a);i<=(b);i++)
using namespace std;
int x[500005],all;
signed main(){
	freopen("mlgrate.in","r",stdin);
	freopen("mlgrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,q;
	cin >> c >> q;
	while(q--){
		int n,d;
		cin >> n >> d;
		f(i,1,n){
			cin >> x[i];	
			all+=x[i];
		}
		int lab=(x[n]-x[1])/2;
		//f(i,1,n){
			if (d>lab&&lab>2){
				cout << 0 << '\n';
			}
			else{
				cout << ((n-1)/2) << '\n';
		}
			
		//}
	}
	return 0;
}
