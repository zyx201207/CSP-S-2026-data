#include<bits/stdc++.h>
using namespace std;
long long int n,st,en,sum;
struct node{
	long long int l;
	char c;
}a[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i].l>>a[i].c;
	st=1;
	en=n;
	while(st<en)
	{
		if(a[st].l>a[en].l)
		{
			a[st].l-=a[en].l;
			if(a[st].c!=a[en].c)
				sum+=a[en].l;
			en--;
		}
		else if(a[st].l<a[en].l)
		{
			a[en].l-=a[st].l;
			if(a[st].c!=a[en].c)
				sum+=a[st].l;
			st++;
		}
		else if(a[st].l==a[en].l)
		{
			if(a[st].c!=a[en].c)
				sum+=a[st].l;
			st++;
			en--;
		}
	}
	cout<<sum;
	return 0;
}
