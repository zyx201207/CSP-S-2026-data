#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005];
long long ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];	
	ans[a[n]]=n;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			int v=0;
			for(int k=n;k>=j+1;k--)
			{
				if(a[k]==a[j])
				{
					j=k;
					break;
				}
				v=1;
			}
			if(v==1)
			ans[a[j]]++;
		}
	} 
	for(int i=1;i<=m;i++)
	cout<<ans[i]<<' ';
	return 0;
}
