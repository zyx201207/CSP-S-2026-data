#include<bits/stdc++.h>
#define int long long
#define uint unsigned int
#define all(x) x.begin(),x.end()
#define inf 0x3f3f3f3f
using namespace std;
const int maxN = 3e5 + 5;
int n,m; int a[maxN]; int table[maxN];
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=0;i<n;i++) cin >> a[i];
	for(int i=0;i<n;i++){
		if(a[i] == i+1) cout << i+1 << " ";
	}
	return 0;
}
