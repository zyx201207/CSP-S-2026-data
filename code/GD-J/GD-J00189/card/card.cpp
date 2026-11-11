#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll sta[500005],n,m,a[500005],top,b[300005],ans[300005];
bool A=true;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=2;i<=n;i++) if(a[i]<a[i-1]) A=false;
	if(A)
	{
		for(int i=1;i<=n;i++)
		{
			ans[a[i]]=i;
			//for(int j=1;j<=m;j++) cout<<b[j]<<' ';
			//cout<<'\n';
		}
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			top=0;
			for(int k=1;k<=m;k++) b[k]=0;
			for(int j=i;j<=n;j++)
			{
				if(b[a[j]]==0) sta[++top]=a[j],b[a[j]]=1;
				else
				{
					while(sta[top]!=a[j])
					{
						b[sta[top]]=0;
						top--;
					}
				}
			}
			for(int k=1;k<=m;k++) if(b[k]) ans[k]++;
			//for(int j=1;j<=m;j++) cout<<b[j]<<' ';
			//cout<<'\n';
		}
	}
	
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}//假战！我抽8张牌！25攻的sdkfz！ 
