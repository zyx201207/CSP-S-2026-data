#include <bits/stdc++.h>
using namespace std;

const int N = 2000005;
int c, t, n;
long long d, x[N]; 

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	cin >> c >> t;
	if(c == 11 || c == 12){
		while(t--){
			cin >> n >> d;
			for (int i= 1;i<=n;i++)
				cin >> x[i];
			
			if(d<(x[2]-x[1])*2){
				cout << 0 << endl;
			}	
			else{
	  			d = d/(x[2]-x[1]);
				d = d+d-1;
				if(n>=d)
					cout << n-d << endl;
				else
					cout << 0;
			}
		}
	}
	
	return 0;
};
