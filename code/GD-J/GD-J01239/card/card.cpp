#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],pp[1000010],ans[500005],p[500005],ppp[500005],b[500005],l;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		p[a[i]]++;
	}
	for(int i=1;i<=n;i++)
	{
		l=0;
		for(int j=1;j<=n;j++)ppp[a[j]]=0;
		for(int j=1;j<=n;j++)b[j]=0;
		for(int j=i;j<=n;j++)
		{
			if(ppp[a[j]]==0)l++,b[l]=a[j],ppp[a[j]]++;
			else
			{
				for(int k=l;k>=1;k--)
				{
					if(a[k]==a[j])
					{
						break;
					}
					ppp[a[k]]--;
					b[l]=0;
					l--;
				}
			}
		}
		for(int j=1;j<=l;j++)
		{
			ans[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
