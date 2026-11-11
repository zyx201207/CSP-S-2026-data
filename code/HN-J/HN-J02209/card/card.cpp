#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],aa[200005],len=0,c[300005],e[300005],chen_zhe[300005];//chen_zhe：关我何事？！ 
bool b[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		memset(b,0,sizeof(b));
		memset(e,0,sizeof(e));
		for(int j=i;j<n;j++)
		{
			if(b[a[j]]==true)
			{
				for(int k=c[a[j]]-1;k<len;k++)
				{
					if(e[aa[k]]>0)
					{
						e[aa[k]]--;
						if(e[aa[k]]==0)
						{
							b[aa[k]]=false;
							chen_zhe[aa[k]]--;
						}
					}
				}
				len=c[a[j]]-1;
			}
			aa[len]=a[j];
			len++;
			c[a[j]]=len;
			e[a[j]]++;
			if(b[a[j]]==false)
			{
				chen_zhe[a[j]]++;
			}
			b[a[j]]=true;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<chen_zhe[i]<<" ";
	}
	return 0;
}
/*
我常常回忆过去...... 

（请前往 www.洛谷.com 下载全文） 
*/
