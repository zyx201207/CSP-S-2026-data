#include<bits/stdc++.h>
using namespace std;
int a[500010],b[500010],ans[300010],k=1;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	b[0]=a[0];
	ans[a[0]]++;
	a[n]=-1;
	for(int i=1;i<=n;i++)
	{
		if(a[i-1]==a[i])
		{
			ans[a[i]]++;
			//cout<<a[i]<<' '<<ans[a[i]]<<endl;
		}
		else
		{
			cout<<ans[a[i-1]]<<' ';
			ans[a[i]]=ans[a[i-1]]+1;
			b[k]=a[i];
			k++;
		}
	}
	return 0;
}
