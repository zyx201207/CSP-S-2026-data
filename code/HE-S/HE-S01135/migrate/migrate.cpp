#include<bits/stdc++.h>
using namespace std;
int a[10001];
int b[10001];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int q=0;
	for(int i=0;i<m;i++)
	{
		int x,y;
		cin>>x>>y;
		int da=0;
		for(int j=0;j<=x;j++)
		{
		cin>>a[j];
		for(int k=0;k<j;k++)
		{
		int sum=max(a[j],a[k]);
		int ans=min(a[j],a[k]);
			if(sum-ans>y)
			{
				da=1;
				continue;
			}else{
				da=0;
			}
		}
	    }
	    if(da==1)
		{
			b[q]=0;
			q++;
		}
	}
	for(int i=0;i<q;i++)
	{
		cout<<b[i]<<endl;
	}
	return 0;
} 
