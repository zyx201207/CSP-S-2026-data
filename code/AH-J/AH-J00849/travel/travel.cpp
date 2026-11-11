#include<iostream>
using namespace std;
string x,z,x1,z1;int a,b,c,d;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>x>>z>>x1>>z1;
    if(x==x1)
    {
		cout<<"1";
		a=1;
	}
    else cout<<"0";
    
    
    
    if(a==1)
    {
		if(z[1]==z1[1] && z[0]==z1[0])
		{
			cout<<"1";
			b=1;
		}
		else cout<<"0";
	}
    else cout<<"0";
    
    
    
    if(b==1)
    {
		if(z[2]-'A'<=2 || z1[2]-'A'<=2)
		{
			cout<<"1";
			c=1;
		}
		else if(z[2]-'A'>=3 || z1[2]-'A'>=3)
		{
			cout<<"1";
			d=1;
		}
		else cout<<"0";
	}
    else cout<<"0";
    
    
    if(d==1)cout<<"1";
    else if(c==1)
    {
		if(z[2]-'A'==1 ||z[2]-'A'==1)cout<<"0";
		else cout<<"1"; 
	}
	else cout<<"0";
    return 0;
}
