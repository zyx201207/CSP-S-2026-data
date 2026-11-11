#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;
int n,m;
int a[maxn],b[maxn];
int d[maxn],dk[maxn],last[maxn];
int rd[maxn],rdk[maxn],rl[maxn];
int lowbit(int x) {return x & -x;}
void add1(int x,int v)
{
	while(x <= n) {d[x] += v;x += lowbit(x);}
}
void add2(int x,int v)
{
	while(x <= n) {dk[x] += v;x += lowbit(x);}
}
int query1(int x)
{
	int res = 0;
	while(x > 0) {res += d[x];x -= lowbit(x);}
	return res;
}
int query2(int x)
{
	int res = 0;
	while(x > 0) {res += dk[x];x -= lowbit(x);}
	return res;
}
int Sum(int x) {return (x + 1) * query1(x) - query2(x);}
int q(int x) {return Sum(x) - Sum(x-1);}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i],b[i] = a[i] - a[i-1];
	add1(1,1);add2(1,1);
	/*for(int i = 1;i <= n;i++)
	{
		add1(i,1);
		add2(i,1 * i);
	}*/
	memset(b,0,sizeof b);
	for(int i = 1;i <= n;i++)
	{
		last[i] = b[a[i]];
		b[a[i]] = i;
	}
	/*cout << "last[i]:";
	for(int i = 1;i <= n;i++) cout << last[i] << " ";
	cout << endl;
	cout << "q(i):";
	for(int i = 1;i <= n;i++) cout << q(i) << " ";
	cout << endl;*/
	memset(b,0,sizeof b);
	for(int i = 1;i <= n;i++) rd[i] = d[i],rdk[i] = dk[i],rl[i] = last[i];
	for(int k = 1;k <= n;k++)
	{
		for(int i = k;i <= n;i++)
		{
			int j = last[i];
			while(j >= k && q(j) <= 0) j = last[j];
			last[i] = j;
			if(j < k) continue;
			add1(j,-1);add1(i,1);
			add2(j,-1 * j);add2(i,1 * i);
			//cout << j << "到" << i - 1 << "减1" << endl;
		}
		for(int i = k;i <= n;i++)
			if(q(i) > 0) b[a[i]]++;
		/*cout << "last[i]:";
		for(int i = 1;i <= n;i++) cout << last[i] << " ";
		cout << endl;
		cout << "q(i):";
		for(int i = 1;i <= n;i++) cout << q(i) << " ";
		cout << endl;*/
		for(int i = k;i <= n;i++) d[i] = rd[i],dk[i] = rdk[i],last[i] = rl[i];
	}
	for(int i = 1;i <= m;i++) cout << b[i] << " ";
    return 0;
}
