# include <bits/stdc++.h>
# define N 100500
using namespace std;
long long n , num[N] , a[N] , str[N] , ans , md , cc;
string s,c;

int main()
{
	freopen("string.in" , "r" , stdin);
	freopen("string.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	s=" "+s;
	for(int i=1;i<=n;i++)
	{
		cin>>num[i]>>c;
		for(int j = 1;j<=num[i];j++)
		 s=s+c;
	}
	for(int l=1,r=n;l<=n/2;l++,r--)
	 if(s[l]!=s[r])
	  ans++;
     cout << ans;
	
	
}