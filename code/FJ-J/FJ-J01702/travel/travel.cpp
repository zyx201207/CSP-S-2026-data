#include<iostream>
#include<string> 
using namespace std;
int main()
{
	freopen("travel.in","r",stdin)
	freopen("travel.out","w",stdout)
	string r,x,sum,a,b;
	cin>>r>>a>>x>>b;
	if(r[0]==x[0]&&r[1]==x[1])
	{
		sum+="1";
	}
	else
	{
		cout<<"0000";
		return 0; 
	}
	if(a[0]==b[0]&&a[1]==b[1])
	{
		sum+="1";
		cout<<"1111";
	}
	else
	{
		sum+="0";
		cout<<"1011";
    }   
	return 0;
}
