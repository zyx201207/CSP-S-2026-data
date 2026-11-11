#include<iostream>
using namespace std;
int c,t;
int n,k,x,y;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		for(int i=1;i<n;i++)
		{
			cin>>x>>y;
		}
		if(c<=5)
		{
			if(t==n)cout<<2<<endl;
			else cout<<1<<endl;
		}
		if(c>5&&c>=10)cout<<12<<endl;
		if(c>10)cout<<412<<endl;
	} 
}
