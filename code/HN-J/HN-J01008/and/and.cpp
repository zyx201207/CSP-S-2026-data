#include<bits/stdc++.h>
using namespace std;
int w[10005][10005];
int y[100005];
int main()
{	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,l=1,lin=0;
	int a[10005]; 
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		lin=a[i];
		l=1;
		while(lin!=0)
		{
			w[i][l]=lin%2;
			lin=lin/2;
			y[i]=y[i]+1;
		}
	}
	for(int i=y[1];i>0;i--)
	{
		cout<<w[1][i];
	}	
	
}
