#include<bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2e5 + 7;

int n;
struct node{
	char ch;
	int pos;
}s[N];
node ql[N], qr[N];
int l1=1, r1=0, l2=1, r2=0;

int L[N], t;

signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	if(n == 1)
	{
		cout<<0;
		return 0;
	}
	int sum = 0;
	int temp = INT_MAX;
	int maxn = INT_MIN;
	bool flag = 1;
	for(int i=1;i<=n;i++)
	{
		int a;
		char c;
		cin>>a>>c;
		sum += a;
		s[i] = {c, sum};
		//cout<<c<<" "<<sum<<"\n";
		if(n == 2) temp = min(temp, a);
		if(a != 1) flag = 0;
		maxn = max(maxn, a);
	}
	if(n == 2)
	{
		if(s[1].ch == s[2].ch)
		{
			cout<<0;
			return 0;
		}
		cout<<temp;
		return 0;
	}
	if(flag)
	{
		int ans = 0;
		for(int i=1;i<=n/2;i++)
		{
			if(s[i].ch != s[n-i+1].ch)
				ans ++;
		}
		cout<<ans;
		return 0;
	}
	if(n * maxn <= 100000000)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=s[i].pos-s[i-1].pos;j++)
			{
				L[++t] = s[i].ch;
			}
		}
		
		int ans = 0;
		for(int i=1;i<=t/2;i++)
		{
			if(L[i] != L[t+1-i])
				ans++;
		}
		cout<<ans;
		return 0;
	}
	
	for(int i=1;i<=n;i++)
	{
		int pos = s[i].pos, ch = s[i].ch;
		if(pos >= sum/2)
		{
			ql[++r1] = {ch, sum/2-s[i-1].pos};
			break;
		}
		ql[++r1] = {ch, pos-s[i-1].pos};
	}
	for(int i=n;i>=1;i--)
	{
		int pos = sum-s[i-1].pos, ch = s[i].ch;
		if(pos >= sum/2)
		{
			qr[++r2] = {ch, sum/2-(sum-s[i].pos)};
			break;
		}
		qr[++r2] = {ch, pos-(sum-s[i].pos)};
	}

	int ans = 0;
	while(l1 <= r1 && l2 <= r2)
	{
		int len1 = ql[l1].pos, len2 = qr[l2].pos;
		char c1 = ql[l1].ch, c2 = qr[l2].ch;
		
		if(len1 < len2)
		{
			qr[l2].pos -= len1;
			l1++;
			if(c1 != c2) ans += len1;
			continue; 
		}
		
		if(len1 > len2)
		{
			qr[l1].pos -= len2;
			l2++;
			if(c1 != c2) ans += len2;
			continue; 
		}
		
		if(len1 == len2)
		{
			l1++;
			l2++;
			if(c1 != c2) ans += len1;
			continue;
		}
	}
	cout<<ans;
	
	return 0;
}
