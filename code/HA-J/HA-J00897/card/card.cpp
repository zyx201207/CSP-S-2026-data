#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("r","card.in",stdin);
	freopen("w","card.out",stdout);
	int www[300005],uuu[300005],hhh[300005];
	int n,m,aaa[500005];
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>aaa[i];
		www[aaa[i]]++;
		hhh[aaa[i]]++;
	}
	uuu[aaa[n]]=n;
	hhh[aaa[n]]--;
	for(int i=n-1;i>=1;i--)
	{
		int o=0;
		hhh[aaa[i]]--;
		if(hhh[aaa[i]]==0)
		{
			for(int j=i-1;j>=1;j--)
			{
				if(hhh[aaa[j]]>=1 && www[aaa[j]]>hhh[aaa[j]])
				{
					uuu[aaa[i]]=max(uuu[aaa[i]],i-j+o);
					break;
				}
				if(j==1)
				{
					uuu[aaa[j]]=max(uuu[aaa[j]],j);
				}
			}
		}
		if(hhh[aaa[i]]!=0)
		{
			uuu[aaa[i]]=max(uuu[aaa[i]],i);
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<uuu[i]<<" ";
	}
	return 0;
}
