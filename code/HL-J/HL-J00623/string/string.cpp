#include<bits/stdc++.h>
using namespace std;
const int maxn=200100; 
struct Node{
	long long a;
	char c;
}ass[maxn];
long long ans=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long cnt=0;
	for(int i=1;i<=n;i++)
	{
		cin>>ass[i].a>>ass[i].c;
		cnt+=ass[i].a;
	}
	cnt/=2;
	long long m=0;
	long long dk=0;
	for(int i=1;i<=n;i++)
	{
		if(m>cnt&&m-ass[i-1].a<cnt)
		{
			dk=cnt-m+ass[i-1].a;
			break;
		}
		if(m>cnt&&m-ass[i-1].a>cnt)
		{
			dk=m-ass[i].a-cnt;
			break;
		}
		else if(m==cnt)
		{
			break;
		}
		m+=ass[i].a;
		
	}
	int r=n;
	for(int i=1;i<=n;i++)
	{ 
		while(ass[i].a>0)
		{
			if(ass[i].a>ass[r].a&&ass[i].c!=ass[r].c)
			{
				ass[i].a-=ass[r].a;
				ans+=ass[r].a;
				ass[r].a=0;
				r--;
			}
			else if(ass[i].a<ass[r].a&&ass[i].c!=ass[r].c)
			{
				ass[r].a-=ass[i].a;
				ass[i].a=0;
				ans+=ass[r].a-ass[i].a;
				break;
			}
			else if(ass[i].a==ass[r].a&&ass[i].c!=ass[r].c)
			{
				ans+=ass[i].a;
				ass[i].a=0;
				ass[r].a=0;
				r--;	
			} 
			else if(ass[i].a>ass[r].a&&ass[i].c==ass[r].c)
			{
				ass[r].a=0;
				r--;
			}
			else if(ass[i].a<ass[r].a&&ass[i].c==ass[r].c)
			{
				ass[r].a-=ass[i].a;
				ass[i].a=0;
				break;
			}
			else
			{
				r--;
				break;
			}
		}
	}
	cout<<ans-dk;
	return 0;
} 
