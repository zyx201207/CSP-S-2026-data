#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,p,q;
	cin>>n>>m;
	int a[500005],b[500005],ans[300005]; 

	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i-1]=0;
		ans[i]=0;
	} 
	
	for(int i=1;i<=n;i++)//n局 
	{
		p=0;//场上牌数 
		for(int j=i;j<=n;j++)//依次出完i至n张牌 
		{
			q=-1;
			for(int l=0;l<p;l++)
			{
				if(b[l]==a[j]) q=l;
			}
			if(q==-1)
			{
				b[p]=a[j];
				p++;
			}
			else
			{
				for(;q<n;q++)
				{
					b[q]=0;
					p--;
				}
			}
			
		}
//		for(int i=0;i<p;i++)
//		{
//			ans[b[i]]+=1;
//		}
		for(int i=0;i<n;i++)
		{
			b[i]=0;
		}
		
	}
	
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i];
	}
}
