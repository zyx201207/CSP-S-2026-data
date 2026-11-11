#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
#define int long long
struct node
{
	int num;
	char c;
}st[N];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int a;
		char c;
		cin>>a>>c;
		st[i].num=a;
		st[i].c=c;
	}
	int ans=0;
	int i=1,j=n;
	while(i<j)
	{
		if(st[i].c!=st[j].c)
		{
			if(st[i].num<st[j].num)
			{
				ans+=st[i].num;
				st[j].num-=st[i].num;
				i++;
			}
			else if(st[i].num>st[j].num)
			{
				ans+=st[j].num;
				st[i].num-=st[j].num;
				j--;
			}
			else
			{
				ans+=st[i].num;
				i++;
				j--;
			}
		}
		else
		{
			if(st[i].num<st[j].num)
			{
				st[j].num-=st[i].num;
				i++;
			}
			else if(st[i].num>st[j].num)
			{
				st[i].num-=st[j].num;
				j--;
			}
			else
			{
				i++;
				j--;
			}
		}
	}
	cout<<ans;
	return 0;
}

