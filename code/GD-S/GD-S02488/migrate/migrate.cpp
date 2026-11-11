#include<bits/stdc++.h>
using namespace std;
const int N = 2*1e6+6;

int n,d,a[N],c,T;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin >> c >> T;
	while(T--){
		cin >> n >> d;
		for(int i=1;i<=n;i++) cin >> a[i];
		if(c == 11 || c == 12)
			if(d/(a[2]-a[1]) == 2 && n>=4){
				int ans = 1;
				ans += n-4;
				cout << ans << endl;
			}
		
	}
	
	return 0;
}
/*
11 2
4 2
1 2 3 4
5 2
1 2 3 4 5

3
0 1 2 4 5
*/
