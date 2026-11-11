#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		int m=n/2;
		if(m==1)
		{
			if(k<3)cout<<1<<'\n';
			else cout<<0<<'\n';
		}
		else if(m==2)
		{
			if(k==1)cout<<2<<'\n';
			else if(k>=2&&k<=4)cout<<1<<'\n';
			else cout<<0<<'\n';
		}	
		else if(m==3)
		{
			if(k==1)cout<<3<<'\n';
			else if(k>=2&&k<=6)cout<<1<<'\n';
			else cout<<0<<'\n';
		}
	}
	return 0;
}


