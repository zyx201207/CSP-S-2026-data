#include<iostream>
#include<cstdio>
using namespace std;
int n,m,a[500001],ans[300001];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++)
    {
      cin>>a[i];
      ans[a[i]]=i;
    }
    for(int i=1; i<=m; i++)
      cout<<a[i]<<' ';
	return 0;
}

