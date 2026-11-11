#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 0x3f3f3f3f
int n;
int num[200010],lp,rp;
int word[200010];
ll ans = 0;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 0;i<n;i++)
	{
		char a;
		cin >> num[i] >> a;
		word[i] = a - 'a';
	}
	rp = n-1;
	while(lp < rp)
	{
		int add = 0;
		if(word[lp] != word[rp]) add = 1;
		if(num[lp] > num[rp])
		{
			ans += num[rp] * add;
			num[lp] -= num[rp];
			rp--;
		}
		else if(num[lp] < num[rp])
		{
			ans += num[lp] * add;
			num[rp] -= num[lp];
			lp++;
		}
		else {ans += num[rp] * add;rp--,lp++;}
	}
	cout << ans;
	return 0;
} 
