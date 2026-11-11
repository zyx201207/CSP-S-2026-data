#include<bits/stdc++.h>//最后一个数字一定会出现n次
using namespace std;
long long n,m,a[500005],ans[300005],p[500005];
bool pp=false;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(a[i]==a[j])
			{	
				
			}
		}
	}
	if(n==m)
	{
		for(int i=1;i<=m;i++)
		{
			cout<<i<<" ";
		}
		return 0;
	}
	ans[a[n]]=n;
	int shu=1;
	while(shu<=m)
	{
		
		shu++;
	}
	return 0;
}
