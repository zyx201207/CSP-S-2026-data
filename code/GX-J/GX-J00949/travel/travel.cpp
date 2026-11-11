#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>c>>b>>d;
	bool p;
	if (c[2]=='A'||c[2]=='B'||c[2]=='C') p=1;
	else p=0;
	if(a==b) cout<<1;
	else
	{
        cout<<0;
        cout<<0;
        cout<<0;
        cout<<0;
        return 0;
	}
	if(a==b&&c[0]==d[0]&&c[1]==d[1]) cout<<1;
	else
	{
        cout<<0;
        cout<<0;
        cout<<0;
        return 0;
	}
	if(a==b&&p)
	{
		if((c[2]=='A'||c[2]=='B'||c[2]=='C')&&(d[2]=='A'||d[2]=='B'||d[2]=='C'))
		{
			cout<<1;
		}
	}
	else if(a==b&&!p)
	{
		if((c[2]=='D'||c[2]=='F')&&(d[2]=='D'||d[2]=='F'))
		{
			cout<<1;
		}
	}
	else
    {
        cout<<0;
        cout<<0;
        return 0;
    }
	if((c[2]=='A'&&d[2]=='B')||(d[2]=='A'&&c[2]=='B')||(c[2]=='B'&&d[2]=='C')||(d[2]=='B'&&c[2]=='C')||(c[2]=='D'&&d[2]=='F')||(d[2]=='D'&&c[2]=='F'))
	{
		cout<<1;
	}
	else
    {
        cout<<0;
    }


	return 0;
}

