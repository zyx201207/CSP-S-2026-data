#include<bits/stdc++.h>
#define int long long
#define il inline
#define pii pair<int,int>

using namespace std;
string c1,s1,c2,s2;
il int read()
{
	int res,f=1;
	char ch;
	while(ch=getchar(),ch<'0'||ch>'9')
		if(ch=='-')
			f=-1;
	res=ch-'0';
	while(ch=getchar(),ch>='0'&&ch<='9')
		res=res*10+ch-'0';
	return res*f;
}

signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]==c2[0]&&c1[1]==c2[1])
	{
		cout<<'1';
		if(s1[0]==s2[0]&&s1[1]==s2[1])
		{
			cout<<'1';
			if((s1[2]<'D'&&s2[2]<'D')||(s1[2]>'C'&&s2[2]>'C'))
			{
				cout<<'1';
				if(abs(s1[2]-s2[2])==1)
					cout<<"1\n";
				else
					cout<<"0\n";
			}
			else
				cout<<"00\n";
		}
		else
			cout<<"000\n";
	}
	else
		cout<<"0000\n";
	return 0;
}

