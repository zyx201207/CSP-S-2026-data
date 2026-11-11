#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005];
int q[500005];
long long ans[500005];
int fd(int tar,int tail)
{
	for(int i=0;i<=tail;i++)
	{
		if(q[i]==tar) return i;
	}
	return -1;
}
int main()
{
	freopen("card.in","r",stdin);	
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++)
	{
		int tail=0;
		memset(q,0,sizeof(q));
		for(int j=i;j<n;j++)
		{
			int temp=a[j];
			if(fd(temp,tail)!=-1) tail=fd(temp,tail);
			else tail++;
			q[tail]=temp;
		}
		for(int z=1;z<=tail;z++) ans[q[z]]++;
	}
	for(int i=1;i<=m;i++)
	{
		if(ans[i]>0) cout<<ans[i]<<" ";
	}
	return 0;
}

