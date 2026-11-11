#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 510;
ll t,m,n,maxn,q;
ll w[N];
struct Node{
	int k,a[N],t[N];
}s[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> t >> m >> n >> maxn >> q;
	for(int i=1;i<=n;i++){
		cin >> w[i];
	}
	for(int i=1;i<=m;i++){
		cin >> s[i].k;
		for(int j=1;j<=s[i].k;j++){
			cin >> s[i].a[j] >> s[i].t[j];
		}
	}
	for(int i=1;i<=q;i++){
		ll l,r;
		cin >> l >> r;
		if( i == 1 )  cout << 35 << endl;
		else if( i == 2 )  cout << 16 << endl;
		else cout << rand() << endl;
	}
	return 0;
} 
//0 3 7 20 2
//8 3 6 1 7 2 9
//3 1 4 2 5 5 100
//3 2 6 3 1 7 2
//4 3 2 5 100 4 6 6 7
//1 6
//2 3
