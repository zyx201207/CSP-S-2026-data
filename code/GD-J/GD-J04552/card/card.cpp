#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],zuo[500010],pai[500010];
long long ans[500010],k;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		k=0;
		int j;
		bool b=false;
		memset(pai,0,sizeof(0));
		memset(zuo,0,sizeof(0));
		for(j=i;j<=n;j++)
		{
			if(zuo[a[j]]==0){
				zuo[a[j]]++;
				pai[++k]=a[j];
			}
			else{
				int p;
				for(p=1;p<=k;p++){
					if(a[j]!=pai[p])continue;
					else break;
				}
				for(int w=p;w<=k;w++){
					zuo[pai[w]]--;
				}
				k=p;
				pai[k]=a[j];
				zuo[a[j]]++;
			}
		}
		for(int w=1;w<=k;w++)
		{
			ans[pai[w]]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
 } 
