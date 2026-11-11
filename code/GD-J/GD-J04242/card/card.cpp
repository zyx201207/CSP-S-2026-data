#include<bits/stdc++.h>
using namespace std;
int n,m,x,k=1;
int a[500001],b[300001];
int find(int x)
{
	for(int i=1;i<=n;i++)
	{
		if(a[i]==x)return i;
	}
	return -1;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.in","w",stdout);
	cin>>n,m;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		if(find(x)!=-1){
			k=find(x);
			for(int j=k;j<=n;j++)
			{
				a[i]=0;
			}
			a[k]=x;
			
		}
		else a[k++]=x;
		for(int j=1;j<=n;j++)
		{
			b[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<b[i]<<" ";
	}
	
}
