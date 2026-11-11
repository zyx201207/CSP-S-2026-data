#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN =  2 * 1e5 + 5;
int a[MAXN];
char b[MAXN];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll cur = 0, ans = 0;
	ll n;
	cin>>n;
	for(int i = 1; i <= n; i++)
	{
		cin>>a[i]>>b[i];
		cur += a[i];
	}
	int num = (cur + 1) / 2;
	for(int i = 0; i <= num; i++)
	{
		for(int j = cur - 1; j > num; j--)
		{
			if(b[i] != b[j])
			{
				ans++;
			}
			b[i] = b[i + 1];
			b[j] = b[j - 1];
		}
	}
	cout<<ans<<endl;
	return  0;
}
