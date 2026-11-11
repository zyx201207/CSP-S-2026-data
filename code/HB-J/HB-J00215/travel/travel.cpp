#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b,c,d;
	char m,n;
	string p,q;
	cin>>a>>p>>b>>q;
	c=p[0]*10+p[1];d=q[0]*10+q[1];m=p[2];n=q[2];
	if(a==b)
	{
		cout<<"1";
		if(c==d)
		{
			cout<<"1";
			if(('A'<=m && m<='C' && 'A'<=n && n<='C')||('D'<=m && m<='B' && 'D'<=n && n<='B'))
			{
				cout<<"1";
				if((m=='A' && n=='B')||(m=='B' && n=='A')||(m=='B' && n=='C')||(m=='C' && n=='B')||(m=='D' && n=='F')||(m=='F' && n=='D'))cout<<"1";
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
