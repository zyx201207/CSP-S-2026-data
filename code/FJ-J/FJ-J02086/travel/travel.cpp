#include<bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	int rcar,xcar;
	string rnum,xnum;
	cin>>rcar;
	cin>>rnum;
	cin>>xcar;
	cin>>xnum;
	if(rcar==xcar)
	{
		cout<<1;
		int a,b;
		a=rnum[0]-'0';
		a=a*10+rnum[1]-'0';
		b=xnum[0]-'0';
		b=b*10+xnum[1]-'0';
		if(a==b)
		{
			cout<<1;
			if((rnum[2]>='D'&&xnum[2]>='D')||(rnum[2]<='C'&&xnum[2]<='C'))
			{
				cout<<1;
				if(abs(rnum[2]-xnum[2])==1)
				{
					cout<<1;
				}
				else
				{
					cout<<"0";
				}
			}
			else
			{
				cout<<"00";
			}
		}
		else
		{
			cout<<"000";
		}
	}
	else
	{
		cout<<"0000";
	}
	return 0;
}
