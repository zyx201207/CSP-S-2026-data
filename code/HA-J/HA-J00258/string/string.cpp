#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long cnt;
int n;
struct s
{
	long long a;
	char c;
}x[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i].a>>x[i].c;
	}
	for(int i=1,j=n;i<=j;)
	{
		if(x[i].c!=x[j].c)
		{
			cnt+=min(x[i].a,x[j].a);
		}
		 long long ls=x[i].a;
			x[i].a-=x[j].a;
			x[i].a=max(x[i].a,0ll);
			x[j].a-=ls;
			x[j].a=max(x[j].a,0ll);
			if(x[i].a==0)
			{
				i++;
			}
			if(x[j].a==0)
			{
				j--;
			}
	}
	cout<<cnt;
	return 0;
}