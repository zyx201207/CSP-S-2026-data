#include<bits/stdc++.h>
using namespace std;
//define int long long
//define int __int128
const int N=1e6,A=1e9;
string a1,a2,a3,b1,b2,b3;
signed main()
{

	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	//freopen(".in","w",stdout);
	//freopen(".out","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>a1>>a2>>b1>>b2;
	if(a1!=b1)return cout<<"0000",0;
	if(a2[0]!=b2[0]||a2[1]!=b2[1])return cout<<"1000",0;
	if((a2[2]<'D'&&b2[2]>'C')||(a2[2]>'C'&&b2[2]<'D'))return cout<<"1100",0;
	if((a2[2]=='A'&&b2[2]!='B')||(a2[2]=='B'&&b2[2]!='C'&&b2[2]!='A')||(a2[2]=='C'&&b2[2]!='B')||(a2[2]=='D'&&b2[2]!='F')||(a2[2]=='F'&&b2[2]!='D'))return cout<<"1110",0;
	cout<<"1111";
	return 0;
}

