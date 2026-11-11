#include<bits/stdc++.h>
using namespace std;
string a,b;
int x,y;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>x>>a>>y>>b;
	
	if(x==y)
	{
		cout<<1;
		bool tp=1;
		for(int i=0;i<=1;i++)
		{
			if(a[i]!=b[i])tp=0;
		}
		if(tp==1)
		{
			cout<<1;
			int za,zb;
			if(a[2]=='D'||a[2]=='F')za=2;
			else za=1;
			if(b[2]=='D'||b[2]=='F')zb=2;
			else zb=1;
			if(za==zb)
			{
				cout<<1;
				int c=(int)(a[2])-(int)(b[2]);
				if(c==-1||c==1)cout<<1;
				else cout<<0;
			}
			else cout<<0<<0;
		}
		else 
		{
			for(int i=1;i<=3;i++)cout<<0;
		}
	}
	else
	{
		
		for(int i=1;i<=4;i++)cout<<0; 
	}
	

	return 0;
}
