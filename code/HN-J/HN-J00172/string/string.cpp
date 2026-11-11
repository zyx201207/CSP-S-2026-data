#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N = 2e5 + 10;
int n,m;
struct node{
	int a;
	char c;
	int erfa;
};
node a[N];
signed main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (int i = 1;i <= n;i++){
		cin>>a[i].a;
		cin>>a[i].c;
		a[i].erfa = a[i - 1].erfa + a[i].a;
		m += a[i].a;
	}
	
	int Ri = n,Li = 1;
	int Rsy = a[Ri].a,Lsy = a[Li].a;
	int ans = 0;
	while (1){
		if (Ri <= Li) break;
		if (Rsy < Lsy){
			if (a[Ri].c != a[Li].c) ans += Rsy;
			Ri--;
			Lsy -= Rsy;
			Rsy = a[Ri].a;
		}
		else if (Rsy > Lsy){
			if (a[Ri].c != a[Li].c) ans += Lsy;
			Li++;
			Rsy -= Lsy;
			Lsy = a[Li].a;
		}
		else{
			if (a[Ri].c != a[Li].c) ans += Lsy;
			Li++;
			Lsy = a[Li].a;
			Ri--;
			Rsy = a[Ri].a;
		}
	}
	cout<<ans;
	return 0;
}
/*
CCF NB
*/
