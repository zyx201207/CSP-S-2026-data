//GZ-J00013 ÎÄãüºÆ 
#include <bits/stdc++.h>
using namespace std;
int a[2000005],n,m,ans,cnt=0,cnt2=0;
bool is2(int a)
{
	int b=a+1;
	while(b!=1)
	{
		if(b%2!=0) return 0;
		b/=2;
	}
	return 1;
}

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1; i<=n; i++)
	{
		cin >> a[i];
		if(is2(a[i])) cnt++;
		if(a[i]=i)
		{
			cnt2++;
		}
	} 
	sort(a,a+n);
	
	if(m==1||cnt==n) cout << a[n];
	else if(m==n-1)
	{
		for(int i=n; i>1; i--)
		{
			a[n]&=a[i];
		}
		cout << a[n];
	}
	else if(cnt2==n)
	{
		for(int i=n; i>n-m; i--)
		{
			a[n]&=a[i];
		}
		cout << a[n];
	}

	return 0;
}
