#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string x1,y1,x2,y2;
	cin>>x1>>y1>>x2>>y2;
	bool k=true;
	if(x1==x2)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
		k=false;
	}
	bool t=true;
	long long int len=y1.size();
	if(k==true)
	{
		for(long long int i=0;i<=len-2;i++)
		{
			if(y1[i]!=y2[i])
			{
				t=false;
				break ;
			}
		}
		if(t==false)
		{
			cout<<0;
		}
		else
		{
			cout<<1;
		}	
	}
	else
	{
		cout<<0;
		t=false;
	}
	bool f=true;
	char a=y1[len-1],b=y2[len-1];
	if(t==false)
	{
		cout<<0;
		f=false;
	}
	else
	{
		if((int(a)<=67 and int(b)<=67) or (int(a)>67 and int(b)>67))
		{
			cout<<1;
		}
		else
		{
			cout<<0;
			f=false;
		}
	}
	if(f==false)
	{
		cout<<0;
	}
	else
	{
		if(abs(int(a)-int(b))==1)
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
	}
}
