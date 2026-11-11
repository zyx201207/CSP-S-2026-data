#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;
const int N=1e5+10,maxl=1e3+10; 
int op1,op2;
string s,t;
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>op1>>s>>op2>>t;
	if(op1==op2) cout<<"1";
	else return cout<<"0000",0;
	int x1=(s[0]-'0')*10+(s[1]-'0');
	int x2=(t[0]-'0')*10+(t[1]-'0');
	if(x1==x2) cout<<"1";
	else return cout<<"000",0;
	int pos1=(s[2]-'A'),pos2=(t[2]-'A');
	if(pos1==3) pos1++;
	if(pos2==3) pos2++;
	if((pos1<=2 && pos2<=2)) cout<<"1";
	else
	{
		if(pos1>=4 && pos2>=4) cout<<"11";
		else cout<<"00";
		return 0;
	}
	cout<<((abs(pos1-pos2)==1)? "1":"0");
	return 0;
}
