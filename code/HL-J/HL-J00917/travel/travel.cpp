#include <bits/stdc++.h>
#define int long long
using namespace std;
string a,b,c,d;
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>a>>b>>c>>d;
	if(a != c) cout<<"0000\n";
	else if(b[0] != d[0] || b[1] != d[1]) cout<<"1000\n";
	else if((b[2] >= 'A' && b[2] <= 'C' && d[2] >= 'D' && d[2] <= 'F') || (b[2] >= 'D' && b[2] <= 'F' && d[2] >= 'A' && d[2] <= 'C')) cout<<"1100\n";
	else if((b[2] == 'A' && d[2] == 'C') || ((b[2] == 'C' && d[2] == 'A'))) cout<<"1110\n";
	else cout<<"1111\n";
	return 0;
}