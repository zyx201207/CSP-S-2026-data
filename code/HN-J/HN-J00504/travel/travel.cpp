#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
bool f1,f2,f3;
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	string s1,s2,c1,c2;
	cin>>s1>>s2>>c1>>c2;
	int a=stoi(s1),b=stoi(c1);
	if(a==b)
	{
		f1=true;
		cout<<1;
	} 
	else cout<<0;
	a=(s2[0]-'0')*10+(s2[1]-'0');
	b=(c2[0]-'0')*10+(c2[1]-'0');
	if(s2[0]=='0') a-=10;
	if(c2[0]=='0') b-=10;
	if(f1)
	{
		if(a==b)
		{
			f2=true;
			cout<<1;
		}
		else cout<<0;
	}
	else cout<<0;
	char q=s2[2],w=c2[2];
	bool flag1=false,flag2=false;
	if(q=='A' or q=='B' or q=='C') flag1=true;
	//trueΪA,B,C
	if(w=='A' or w=='B' or w=='C') flag2=true;
	if(f1 and f2)
	{
		if(flag1==flag2)
		{
			f3=true;
			cout<<1;
		} 
		else cout<<0;
	}
	else cout<<0;
	if(f1 and f2 and f3)
	{
		if((q=='A' and w=='B') or (q=='B' and w=='C') or (q=='D' and w=='F') or (w=='A' and q=='B') or (w=='B' and q=='C') or (w=='D' and q=='F'))
		{
			cout<<1;
		}
		else cout<<0;
	}
	else cout<<0;
	return 0;
} 
