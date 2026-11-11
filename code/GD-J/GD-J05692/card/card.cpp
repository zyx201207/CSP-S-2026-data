#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int a[500010]={},ans[500005]={};
int b[500005]={};
bool gett[500005]={};
int n,m;

int main()
{
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for(int i=1;i<=n;i++)
	{
		int cur=1;
		for(int j=i;j<=n;j++)
		{
			if(b[a[j]]<cur && b[a[j]]!=0)
			{
				cur=b[a[j]]+1;
				for(int k=1;k<=n;k++){
					if(b[a[k]]>b[a[j]]) b[a[k]]=0;
				}
			}
			else b[a[j]]=cur++;
			
		}
		for(int j=i;j<=n;j++){
			if(b[a[j]]<cur && b[a[j]]!=0) gett[a[j]]=1;
		}
		for(int j=i;j<=n;j++){
			ans[a[j]]+=(gett[a[j]])?1:0;
			gett[a[j]]=0; 
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<' ';
	}
	return 0; 
 } 
