#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+11;
int n,m;
string s,ss;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0),cout.tie(0);
	cin>>n>>s>>m>>ss;
	if(n==m)
	{
		cout<<'1';
		int t=(s[0]-'0')*10+(s[1]-'0');
		int tt=(ss[0]-'0')*10+(ss[1]-'0');
		if(t==tt)
		{
			cout<<'1';
			if((s[2]>='A' && s[2]<='C' && ss[2]>='A' && ss[2]<='C') || (s[2]>='D' && s[2]<='E' && ss[2]>='D' && ss[2]<='E'))
			{
				cout<<'1';
				if(abs(ss[2]-s[2])==1)cout<<'1';
				else cout<<'0';
			}
			else cout<<"00\n";
		}
		else cout<<"000\n";
	}
	else cout<<"0000\n";
	return 0;
}
/*
8:09 ÅäÖÃÍê³É
T1
rp++ 
8:49 Ok 
*/
