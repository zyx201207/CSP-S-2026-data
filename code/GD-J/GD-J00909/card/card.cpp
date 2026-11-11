#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],t,ans;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	for(int i=1;i<=m;i++)
	{
		t=0,ans=0;
		for(int j=i;j<=n;j++)
		{
			b[++t]=a[j];
			for(int k=1;k<=t;k++)
			{
				if(b[k]==a[j])
				{
					t=0;
					b[++t]=a[j];
				}
			}
		}
		for(int j=1;j<=t;j++)
		if(b[j]==i)ans++;
		cout<<ans<<" ";
	}
	return 0;
}
