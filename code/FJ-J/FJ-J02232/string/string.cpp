#include<bits/stdc++.h>
using namespace std;
long long n,ai,o=1;
string bbq,ci;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>ai>>ci;
		int hhhh;
		if(ai>50) 
		{
			hhhh=ai%50;
			for(int j=50;j<=ai;j+=50)
			{
				bbq+=ci;bbq+=ci;bbq+=ci;bbq+=ci;bbq+=ci;bbq+=ci;bbq+=ci;bbq+=ci;bbq+=ci;bbq+=ci;bbq+=ci;bbq+=ci;bbq+=ci;bbq+=ci;bbq+=ci;bbq+=ci;bbq+=ci;bbq+=ci;bbq+=ci;bbq+=ci;bbq+=ci;bbq+=ci;bbq+=ci;bbq+=ci;bbq+=ci;
				bbq+=ci;bbq+=ci;bbq+=ci;bbq+=ci;bbq+=ci;bbq+=ci;bbq+=ci;bbq+=ci;bbq+=ci;bbq+=ci;bbq+=ci;bbq+=ci;bbq+=ci;bbq+=ci;bbq+=ci;bbq+=ci;bbq+=ci;bbq+=ci;bbq+=ci;bbq+=ci;bbq+=ci;bbq+=ci;bbq+=ci;bbq+=ci;bbq+=ci;
			}
			for(int j=1;j<=hhhh;j++)
			{
				bbq+=ci;
			}
		}
		else
		{
			for(int j=1;j<=ai;j++)
			{
				bbq+=ci;
			}
		}
	}
	int o=bbq.size();
	cout<<o<<endl;
	if(o%2==0)
	{
		long long y=o/2,ans=0;
		int u=0,ll=2;
		while(y--)
		{
			if(bbq.substr(u,1)!=bbq.substr(o-ll,1))
			{
				ans++;
			}
			u++;ll++;
		}
		cout<<ans;
	}
	else
	{
		long long cc=o/2,anso=0;
		int uu=0,lll=2;
		while(cc--)
		{
			if(bbq.substr(uu,1)!=bbq.substr(o-lll,1))
			{
				anso++;
			}
			uu++;lll++;
		}
		cout<<anso;
	}
	return 0;
}
