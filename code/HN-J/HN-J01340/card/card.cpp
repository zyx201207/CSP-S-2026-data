#include<bits/stdc++.h> 
using namespace std;
int last,head,k[500010],n,m,a[500010],wz[500010],ans[500010];
bool rg[500010]; 
int main()
{
	freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
    	
	}
	int j=0;
while(j<n)
{    
	j++;
	last=j,head=j;
	for(int i=j;i<=n;i++)
	{
		if(rg[a[i]]==1)
	{
		head=wz[a[i]]+1;
		for(int i=j;i<=wz[a[i]];i++)
	{
		rg[a[i]]=0;
	}
		}
		last++;
		rg[a[i]]=1;
		wz[a[i]]=last;
	
	}
	for(int i=j;i<=n;i++)
	{
		rg[a[i]]=0;
	}

	for(int i=head;i<=last;i++)
	{
		
		ans[a[i]]++;
	}
	
}
for(int i=1;i<=m;i++)
{
	cout<<ans[i]<<" ";
}
	return 0;
}
