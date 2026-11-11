#include<bits/stdc++.h>
using namespace std;
const int N=200010;
int n,m;
int a[N],b[N];
string s[N];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(m==1)
	{
		int maxn=0;
		for(int i=1;i<=n;i++)
		maxn=max(maxn,a[i]);
		return printf("%d",maxn);
	}
	return 0;
}
