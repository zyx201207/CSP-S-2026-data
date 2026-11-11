#include<bits/stdc++.h>
#define int long long
#define fre freopen("travel.in","r",stdin),freopen("travel.out","w",stdout)
using namespace std;
string a,b,c,d;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	fre,cin>>a>>b>>c>>d;
	if(a==c) cout<<"1";
	else cout<<"0000",exit(0);
	if(b[0]==d[0]&&b[1]==d[1]) cout<<"1";
	else cout<<"000",exit(0);
	if((b[2]<='C'&&d[2]<='C')||(b[2]>'C'&&d[2]>'C')) cout<<"1";
	else cout<<"00",exit(0);
	cout<<(d[2]==b[2]+1||b[2]==d[2]+1);
	return 0;
}
