#include<bits/stdc++.h>
using namespace std;
long long a[5000005],som[100005];
int ans[105][105];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int k=1;k<=n;k++){
		for(int i=k;i<=n;i++)
		{
			if(ans[k][a[i]==1]){
				for(int j=0;j<=i;j++){
					ans[k][a[j]]=0;
				}
				ans[k][a[i]]=1;
			}
			else ans[k][a[i]]=1;
		}
		for(int j=1;j<=m;j++){
				if(ans[k][j]==1) som[j]++;
		}
		for(int i=1;i<=k-1;i++){
			a[i]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout <<som[i]<<" ";
	}
	return 0;
}

