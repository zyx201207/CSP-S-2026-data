#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int cx1,cx2,r1,r2;
char sea1,sea2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	cx1=(c1[0]-'0')*10+(c1[1]-'0');
	cx2=(c2[0]-'0')*10+(c2[1]-'0');
	r1=(s1[0]-'0')*10+(s1[1]-'0');
	r2=(s2[0]-'0')*10+(s2[1]-'0');
	sea1=s1[2];
	sea2=s2[2];
	if(cx1==cx2)
	{
		cout<<1;
		if(r1==r2)
		{
			cout<<1;
			if(((sea1=='A'||sea1=='B'||sea1=='C')&&(sea2=='A'||sea2=='B'||sea2=='C'))||((sea1=='D'||sea1=='F')&&(sea2=='D'||sea2=='F')))
			{
				cout<<1;
				if(((sea1!='C'&&sea2!='D')||(sea1!='D'&&sea2!='C'))&&(sea1-1==sea2||sea2-1==sea1))
				{
					cout<<1;
				}
				else
				{
					cout<<0;
				}
			}
			else
				cout<<"00";
		}
		else
			cout<<"000";
	}
	else
		cout<<"0000";
	return 0;
}
