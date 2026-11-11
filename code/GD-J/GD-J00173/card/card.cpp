#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n,m,a[500005],num[300005],maxi;
ll ans[300005],t;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=m;j++) num[j]=0;
		ll t=0;
		for(int j=i;j<=n;j++)
		{
			if(num[a[j]]!=0)
			{
				for(int k=max(num[a[j]],t);k<j;k++) ans[a[k]]--;
				t=num[a[j]]+1;
			}
			num[a[j]]=i;
			ans[a[j]]++;
		}
		//for(int i=1;i<=m;i++)printf("%lld ",ans[i]);
		//cout<<endl;
	}
	for(int i=1;i<=m;i++)printf("%lld ",ans[i]);
	
	return 0; 
}
