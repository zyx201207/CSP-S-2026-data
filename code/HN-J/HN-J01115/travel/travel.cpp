#include<bits/stdc++.h> 
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string m1,m2,n1,n2;
	cin>>m1>>n1>>m2>>n2;
	int c1=0,c2=0,c3=0,c4=0,a1,a2,b1,b2;
	a1=n1[1]+n1[0];
	a2=n2[1]+n2[0];
	b1=n1[2];
	b2=n2[2];
	if(m1==m2)
	{
		c1=1;
		if(a1==a2)
		{
		    c2=1;
		    if(b1<='C'&&b2<='C'||b1>='D'&&b2>='D')
		    {
		    	c3=1;
		    	if(b1+1==b2||b1-1==b2)c4=1;
			}
		}
	}
	cout<<c1<<c2<<c3<<c4;
	return 0; 
} 
