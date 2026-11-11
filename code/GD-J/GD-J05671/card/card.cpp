#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],t[300005],t1[300005];;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		memset(b,-1,sizeof b);
		int cnt=0;
		for(int j=i;j<=n;j++)
		{
			int x=a[j];
			int f=0;
			for(int k=1;k<=cnt;k++)
			{
				if(b[k]==x)
				{
					f=k;
					break;
				}
			}
			if(f==0)
			{
				b[++cnt]=x;
			}
			else 
			{
				for(int k=f;k<=cnt;k++)
				{
					b[k]=-1;
				}
				cnt=f;
				b[cnt]=x;
			}
//			for(int k=1;k<=cnt;k++) cout<<b[k]<<" ";
//			cout<<endl;
		}
		memset(t1,0,sizeof t1);
		for(int j=1;j<=cnt;j++)
		{
			t1[b[j]]++;
		}
		for(int j=1;j<=m;j++)
		{
			if(t1[j]!=0) t[j]++;
//			cout<<t1[j]<<" ";
			
		}
//		cout<<endl;
	}
	for(int i=1;i<=m;i++)
	{
		cout<<t[i]<<" ";
	}
	
	return 0;
} 
/*4 2
3 15 12 12
*/
