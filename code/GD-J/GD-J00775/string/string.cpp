#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct stu{
    bool d;
	ll c;
	char k; 
};
ll n;
stu a[200001], b[200001];
stu temp;
ll ca, cb;
ll ans;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i ++)
	{
		ll x;
		char y;
		cin >> x >> y;
		a[i].d = 0;
		a[i].c = x;
		a[i].k = y;
		b[n + 1 - i].d = 1;
		b[n + 1 - i].c = x;
		b[n + 1 - i].k = y;
	}
	temp = a[1];
	ca = 1;
	while(ca != n || cb != n)
	{
		stu now;
		if(temp.d == 0)
		{
			cb ++;
			now = b[cb];
		}
		else
		{
			ca ++;
			now = a[ca];
		}
		if(temp.k != now.k)
		{
			ans += min(temp.c, now.c); 
		}
		if(temp.c <= now.c)
		{
			temp.d = !temp.d;
			temp.k = now.k;
		}
		temp.c = abs(temp.c - now.c);
	}
	cout << ans / 2 << "\n"; 
	return 0;
}
