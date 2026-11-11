#include<bits/stdc++.h>
using namespace std;
#define int long long
string a1,a2,b1,b2;bool f[5];
signed main()
{

	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin.tie(0);cout.tie(0);
	cin>> a1 >> a2 >> b1 >> b2;
	f[0]=(a1==b1);f[1]=(f[0] && a2[0]==b2[0] && a2[1]==b2[1]);
	int a=a2[2]-'A',b=b2[2]-'A';
	f[2]=(f[1] && ((a<3 && b<3) || (a>2 && b>2)));
	f[3]=(f[2] && abs(a-b)==1);
	cout<< f[0] << f[1] << f[2] << f[3];

return 0;
}

