#include<bits/stdc++.h>
using namespace std;
struct node
{
	long long m;
	char c;
	bool flag=1;
}a[1000000];
long long sam=0;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].m>>a[i].c;
	} 
	int last=n;
	for(int i=1;i<=n;i++)
	{
		if(a[i].flag==0)
		{
			break;
		}
		long long siz=a[i].m;
		long long siz2=0;
		int r=last;
		while(siz2<siz)
		{
			siz2+=a[r].m;
			if(siz2>a[r].m)
			{
				
				if(a[r].c!=a[i].c)
				{
					sam+=(a[r].m-(siz2-siz));
				}
				a[r].m=siz2-siz;
				
				break;
			}
			if(a[r].c!=a[i].c)
			{
				sam+=a[r].m;
			}
			a[r].flag=0;
			
			r--;
			
		}
		last=r;
		
	}
	cout<<sam;
	return 0;
}
