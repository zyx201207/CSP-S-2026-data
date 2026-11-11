#include<bits/stdc++.h>
using namespace std;

const int N=90001,M=3000;

int n,m,a[N],k[M];
unsigned int lt[M][N];
long long ans[M];

inline int cot(int x,int i)
{
	int l=1,r=k[x],mid;
	while(l<=r)
	{
		mid=l+r>>1;
		if(lt[x][mid]<i)l=mid+1;
		else r=mid-1;
	}
	
	return lt[x][l];
}

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
		lt[a[i]][++k[a[i]]]=i;
	}
	
	for(int i=1;i<=n;++i)
	{
		for(int j=cot(a[n],i);j>=i;j=cot(a[j],i))
		{
			ans[a[j]]++;
			if(j==i)break;
			
			j--;
		}
	}
	
	for(int i=1;i<=m;++i)
		cout<<ans[i]<<' ';
	
	return 0;
}
