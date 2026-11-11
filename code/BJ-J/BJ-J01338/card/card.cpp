#include<bits/stdc++.h>
using namespace std;
int l[500010],a[500010],ans1[500010],ans[500010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,cnt=0;
	cin>>n>>cnt;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=n;i>=0;i--)
	{
		if(l[a[i]]==0) l[a[i]]=i;
	}
	for(int i=1;i<=n;i++)
	{
		int k=i;
		while(k<=n)
		{
			if(k>=l[a[k]]) ans[a[k]]++,k++;
			else k=l[a[k]],ans[a[k]]++;
		}
		for(int j=1;j<=cnt;j++)
		{
			if(ans[j]!=0) 
			{ ans[j]=0;ans1[j]++;
			}
		}
	}
	for(int i=1;i<=cnt;i++)
	{
		cout<<ans1[i]<<" ";
	}
}
