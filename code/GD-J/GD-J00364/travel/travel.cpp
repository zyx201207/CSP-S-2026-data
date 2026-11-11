#include<iostream>
#include<cmath>
using namespace std;
int m,n,a,b;
char c,d;
bool check(char p,char q)
{
	if((p=='D'&&q=='F')||(p=='F'&&q=='D')) return true;
	if(abs(int(p)-int(q))==1) return true;
	return false;
} 
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>m>>a>>c>>n>>b>>d;
	if(m==n)
	{
		cout<<"1";
		if(a==b)
	{
		cout<<"1";
		bool x=false,y=false;
		if(c>='A'&&c<='C') x=true;
		if(d>='A'&&d<='C') y=true;
		if(x==y)
		{
			cout<<"1";
			if(check(c,d)) cout<<"1";
			else cout<<"0";
		}
		else cout<<"00";
	}
	else cout<<"000";	
	}
	else cout<<"0000";
}
