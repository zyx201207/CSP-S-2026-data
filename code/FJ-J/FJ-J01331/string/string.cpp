#include<bits/stdc++.h>
using namespace std;
#define int long long 
//怎么又来一个串串
//好烦，这题卡了最久了 

const int N = 200005;

int n, nw = 0;
int ans = 0;
int a[N], b[N], s[N];
int fa[N], fb[N], fs[N];
char c;

int rn(int x, int y, int nwx, int nwy)
{
	if(y < nwx || nwy < x)return 0;
	return min(y, nwy) - max(x, nwx) + 1;
}

signed main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout); 
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i] >> c;
		b[i] = c - 'a' + 1;
		s[i] = nw;
		nw += a[i];
	}
	s[n + 1] = nw;
	for(int i = 1; i <= n; i++)
	{
		fs[i] = nw - s[n + 2 - i];
		fa[i] = a[n - i + 1];
		fb[i] = b[n - i + 1];
	}
	fs[n + 1] = nw;
	
	for(int i = 1, j = 1; ; )
	{
		if(i > n || j > n)break;
		if(b[i] != fb[j])
		{
			ans += rn(s[i], s[i + 1] - 1, fs[j], fs[j + 1] - 1);
		}
		if(s[i + 1] > fs[j + 1])j++;
		else i++;
	}
	
	cout << ans / 2;
	
	return 0;
}  
