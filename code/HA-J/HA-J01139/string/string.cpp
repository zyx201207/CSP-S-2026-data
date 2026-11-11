#include<bits/stdc++.h>
using namespace std;
long long n;
struct s{
	int a1;
	char a2;
};
s a[100005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i].a1 >> a[i].a2;
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i].a2==a[i+1].a2) cout << '0';
	}
	char b[100005]={};
	if(n%2==0)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i].a2!=a[i-1].a2) b[i]++;
			else b[i-1]++;
		}
		sort(b+1,b+1+n);
		cout << b[n];
	}else
	{
		a[n/2+1].a2=0;
	}
	return 0;
}

