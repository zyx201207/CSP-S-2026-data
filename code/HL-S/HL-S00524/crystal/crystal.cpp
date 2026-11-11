#include<bits/stdc++.h>
#define int long long

using namespace std;

const int N = 5e5 + 7;
int n,m,a[N];
vector<int> vec;
int ans;
int f[N];
bool flag = true;
int d;

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin >> n >> m;
	
	cin >> a[1] >> a[2];
	d = (int)abs(a[1] - a[2]);
	for(int i = 3;i <= n;i++)
	{
		cin >> a[i];
		if( (int)abs(a[i] - a[i-1]) != d){
			flag = false;
		}
	}
	
	sort(a + 1,a + n + 1);
	if(flag){
		for(int i = 1;i <= n;i++)	
		{
			if(i * (i - 1) / 2 * d > m){
				cout << i - 1 << '\n';
				return 0;
			}
		}
		cout << n << '\n';
	}
	else{
		f[0] = f[1] = 0;
		for(int i = 2;i <= n;i++)
		{
			int cnt = 1,sum = 0;
			for(int j = i - 1;j >= 1;j--)
			{
				sum += a[i] - a[j];
				if(sum > m){
					f[i] = cnt;
					break;
				}
				cnt++;
			}
			for(int j = i + 1;j <= n && a[i] == a[j];j++)
			{
				cnt++;
			}
			f[i] = cnt;
		}
		for(int i = 1;i <= n;i++)
		{
			ans = max(ans,f[i]);
		}
		cout << ans << '\n';
	}
	
	return 0;
}
/*I am shanzhenheng
Father and mother I love you!!!Wish you can be happy and healthy!!!
I wish to AK CSP!!!(But I can not and I can get this achievement in the future)
I believe that keep on trying and I will be successful.I will be more hard-work in the future.
*/