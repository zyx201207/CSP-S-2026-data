#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll b;
string ac,az,bc,bz;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>ac>>az>>bc>>bz;
	if(ac!=bc)cout<<"0000";
	else if(az[0]!=bz[0]||az[1]!=bz[1])cout<<"1000";
	else if(az[2]<='C'&&bz[2]>'C'||az[2]>'C'&&bz[2]<='C')cout<<"1100";
	else if(abs(az[2]-bz[2])!=1)cout<<"1110";
	else cout<<"1111";
	return 0;
}
