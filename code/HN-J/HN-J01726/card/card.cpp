#include<bits/stdc++.h>
using namespace std;
int ans[300005],m[300005],n[500005],z[500005],q,w,l;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>q>>w;
	for(int i=1;i<=q;i++)
	{
		cin>>n[i];
	}
	for(int i=1;i<=q;i++)
	{
		for(int j=i;j<=q;j++)
		{
			if(m[n[j]]==1)
			{
				while(z[l]!=n[j])
				{
					m[z[l]]=0;
					l--;
				}
			}
			else
			{
				l++;
				z[l]=n[j];
				m[z[l]]=1;
			}
		}
		while(l>=1)
		{
			ans[z[l]]++;
			m[z[l]]=0;
			l--;
		}
	}
	for(int i=1;i<=w;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}
