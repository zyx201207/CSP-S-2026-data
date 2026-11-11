#include<bits/stdc++.h>
using namespace std;
int a[110];
int b[110];
bool cmp(int x,int y)
{
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,maxn=-1;
	cin>>n>>m;
	for(int i=0; i<=n; i++)
	{
		cin>>a[i]>>b[i];
		a[i]=b[i];
	}
    sort(a+1,a+n+1,cmp);
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=m; j++)
		{
			if(a[i]>maxn)
			{
				maxn=a[i];
			}
		}
		int c=a[i]%b[i];
		cout<<c<<" ";
}
	return 0;
}
