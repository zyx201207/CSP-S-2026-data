#include<bits/stdc++.h>
using namespace std;
int c,t;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	if(c==1)
	{
		for(int i=1;i<=t;i++)
		{
			cout<<1<<endl;
		}
	} 
	else
	{
		for(int i=1;i<=t;i++)
		{
			cout<<(i+2)%(t-i+1)<<endl;
		}
	}
	return 0;
} 
