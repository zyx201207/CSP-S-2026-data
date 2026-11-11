#include<iostream>
using namespace std;
string rc,xc,rs,xs;
//rc=c1,xc=c2,rs=s1,xs=s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>rc>>rs>>xc>>xs;
	char r,x;
	r=rs[2];
	x=xs[2];
	string rp,xp;
	rp=(rs[0]-'0')*10+(rs[1]-'0');
	xp=(xs[0]-'0')*10+(xs[1]-'0');
	if(rc==xc){
		cout<<1;
		if(rp==xp)
		{
			cout<<1;
			if(((r>='A'&&r<='C')&&(x>='A'&&x<='C'))||((r>='D'&&r<='F')&&(x>='D'&&x<='F')))
			{
				cout<<1;
				if(r-x==1||x-r==1)
					cout<<1;
				else
					cout<<0;
			}
			else
				cout<<"00";
		}
		else cout<<"000";
	}
	else
	{
		cout<<"0000";
	}
	return 0;	
} 
