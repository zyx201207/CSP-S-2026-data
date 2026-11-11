
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m;
long long a[200001];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++)
      cin>>a[i];
    sort(a+1,a+n+1);
    cout<<a[n-m-1];
	return 0;
}
