#include<bits/stdc++.h>
using namespace std;
struct node{int a;char c;};
int n;
node str[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long sum=0;
	for(int i=1;i<=n;i++)
	{
		cin>>str[i].a>>str[i].c;
		sum+=str[i].a;
	}
	sum/=2;
	long long ans=0;
	int cntl=1,cntr=0;
	while(sum>0)
	{
		int l=str[cntl].a,r=str[n-cntr].a;
		if(l<r)
		{
			str[cntl].a=0;
			str[n-cntr].a-=l;
			if(str[cntl].c!=str[n-cntr].c)
			{
				ans+=l;
			}
			sum-=l;
			cntl++;
		}
		else if(l>r)
		{
			str[cntl].a-=r;
			str[n-cntr].a=0;
			if(str[cntl].c!=str[n-cntr].c)
			{
				ans+=r;
			}
			sum-=r;
			cntr++;
		}
		else
		{
			str[cntl].a=0;
			str[n-cntr].a=0;
			if(str[cntl].c!=str[n-cntr].c)
			{
				ans+=l;
			}
			sum-=l;
			cntl++;
			cntr++;
		}
	}
	cout<<ans;
	return 0;
}
