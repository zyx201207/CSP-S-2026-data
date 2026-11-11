#include <bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	while(q--)cout<<n*m+d<<"\n";
	return 0;
}