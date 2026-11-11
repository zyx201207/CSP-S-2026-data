#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[100005];
int line[100005];

int	niko(int i,int num)
{
	for(int k=i+1;k<=n;k++)
	{
		if(num>0)
		{
			line[num]=a[k];
			niko(k,num-1);
		}	
			
		if(num==0)
		{
			int v=line[1];
			for(int c=1;c<=m;c++) cout<<line[c]<<' ';
		}
	}
}

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)	cin>>a[i];
	
	int maxn=-1;
	
	for(int i=1;i<=n-1;i++)
	{
		line[m]=a[i];
		maxn=max(maxn,niko(i,m-1));
	}
	cout<<maxn;
}
