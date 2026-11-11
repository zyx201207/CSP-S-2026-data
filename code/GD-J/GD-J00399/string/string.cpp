#include <bits/stdc++.h>
using namespace std;
#define ll long long 
const int N = 2e5 + 7;
int n;

int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	ll ans = 0;
	
	vector<ll> a(n+1,0),pos(n + 1,0);
	vector<char> b(n+1);
	ll l = 1,r = 0;
	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		r += a[i];
		pos[i] = pos[i-1] + a[i];//end
		a[i] = pos[i-1] + 1;//start
	}
	int i = 1,j = n;
	
	while(l < r)
	{
//		cout<<"l: "<<l<<"    "<<"r: "<<r<<endl;
		int len_i = pos[i] - l + 1;
		int len_j = r - a[j] + 1;
		int len = min(len_i,len_j);
//		cout<<"len: "<<len<<endl;
		
		if(b[i] != b[j])
		{
			ans += len;
		}
		l += len;
		r -= len;
		if(len_i < len_j)
		{
			i++;
		}
		else
		{
			j--;
			if(len_i == len_j)
			{
				i++;
			}
		}
//		cout<<"i: "<<i<<"    "<<"j: "<<j<<endl;
//		cout<<"ans = "<<ans<<endl;
	}
	cout<<ans<<endl;
	return 0;
}
/*
3
2 a
2 b
1 c

2
2 a
3 a


6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
