#include<bits/stdc++.h>
using namespace std;
int n,m,len;
int a[500005],book[300005],b[500005],ans[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		memset(book,0,sizeof book);
		memset(b,0,sizeof b);
		len=0;
		for(int j=i;j<=n;j++)
		{
			if(book[a[j]]!=0)
				for(int k=book[a[j]];k<=len;k++) 
				{
					book[b[k]]=0;
					b[k]=0;
				}
			book[a[j]]=len+1;
			b[++len]=a[j];
		}
		for(int j=1;j<=len;j++) ans[b[j]]++;
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}
