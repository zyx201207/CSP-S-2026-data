#include<bits/stdc++.h>
using namespace std;
const int M=2e5+5;
struct node{
	int num;char c;
}a[M];
int n,imin;
long long ans=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i].num>>a[i].c;
	int p=1,q=n;
	while(p<q)
	{
		imin=min(a[p].num,a[q].num);
		if(a[p].c!=a[q].c)
			ans+=imin;
		a[p].num-=imin,a[q].num-=imin;
		if(a[p].num==0)p++;
		else q--;
	}
	cout<<ans;
	return 0;
}
