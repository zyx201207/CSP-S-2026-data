#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=5e5+5;
int a[N],b[N];
struct node
{
	bool x;
	int pos;
}f[N];
int w[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(!f[a[j]].x) f[a[j]].x=1,f[a[j]].pos=j;
			else
			{
				for(int k=1;k<=m;k++)
				{
					if(k==a[j]) continue;
					if(f[k].pos<j&&f[k].pos>=f[a[j]].pos) f[k].x=0;
				}
				f[a[j]].pos=j;
			}
		}
		for(int j=1;j<=m;j++)
		{
			if(f[j].x) w[j]++,f[j].x=0;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<w[i]<<' ';
	}
	return 0;
}
