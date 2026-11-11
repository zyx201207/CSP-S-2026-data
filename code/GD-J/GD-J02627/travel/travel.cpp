#include<bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    string s1,s2,c1,c2;
	cin>>s1>>s2>>c1>>c2;
	if(s1==c1)
	{
		cout<<1;
		if(s2[0]+s2[1]==c2[0]+c2[1])
		{
			cout<<1;
			char s=s2[2],c=c2[2];
			if((s=='A'&&c=='B'||c=='C')||(s=='B'&&c=='A'||c=='C')||(s=='C'&&c=='B'||c=='A')||(s=='D'&&c=='F')||(s=='F'&&c=='D'))
			{
				cout<<1;
				if(abs(c-s)==1||(s=='D'&&c=='F')||(s=='F'&&c=='D'))
				{
					cout<<1;
				}else cout<<"0";
			}else cout<<"00";
		}else cout<<"000";
	}
	else cout<<"0000";
	return 0;
} 
