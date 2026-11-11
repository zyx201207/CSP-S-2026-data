#include<bits/stdc++.h>
using namespace std;
const int M=3*1e5;
int n,m;
int vis[M],a[M],b[M];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>vis[i];
		a[i]=vis[i];
	}
	int sum=n;
	for(int i=1;i<=n;i++)
	{
		int num=1;
		for(int j=1;j<=sum;j++)
		{
			if(a[j]==vis[i]) num=j;
		}
		for(int j=num;j<=sum;j++){
			a[j]=0;
			sum--;
		}
		for(int j=1;j<=m;j++)
		{
			for(int k=1;k<=sum;k++){
				if(a[k]==i) b[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++) cout<<b[i]<<" ";
	return 0;
}

