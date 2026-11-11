#include<bits/stdc++.h>
using namespace std;
int n,m,arr[500010],t1[300010],t2[300010],ans[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
		if(t1[arr[i]]==0)
			t1[arr[i]]=i;
		t2[arr[i]]=i;
	}
	for(int i=1;i<=n;i++)
	{
		int sta=n-i+1;
		for(int j=sta;j<t2[arr[sta]];j++)
		{
			arr[j]=-1;
		}
		for(int j=t2[arr[sta]];j<=n;j++)
		{
			if(arr[j]!=-1) ans[arr[j]]++;
		}
	}
	/*
	for(int i=1;i<=m;i++)
	{
		int ans=INT_MAX;
		bool flag=false;
		for(int j=1;j<=m;j++)
		{
			if(t1[j]>t2[i]&&t2[i]>t2[j])
			{
				for(int k=t2[i];k<=t2[j];k++)
				{
					if(arr[k]==arr[j])
					{
						ans=min(ans,arr[k]-1);
						break;
					}
				}
				flag=true;
			}
		}
		if(!flag)
			ans=n;
		cout<<ans<<" ";
	}
	*/
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
} 
