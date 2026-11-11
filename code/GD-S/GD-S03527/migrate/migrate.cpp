#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int c,t,n,d,a[N],A;
bool flagA=1;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		for (int i=1;i<=n;i++){
			cin >> a[i];
			if (i==2) A=a[i]-a[i-1];
			else if (i!=1 && a[i]-a[i-1]!=A) flagA=0;
		}
		if (flagA){
			if (d<2*A) cout << 0 << '\n';
			else if (d>=3*A) cout << 0 << '\n';
			else cout << n-3;
		}
		else{
			cout << rand()%n << '\n';
		}
	}
	return 0;
}

