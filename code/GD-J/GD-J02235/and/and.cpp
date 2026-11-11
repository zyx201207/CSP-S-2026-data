#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
long long n, a[MAXN], m;
long long maxx = LONG_LONG_MIN; 
string as[MAXN];
string totwo(long long m)
{
	string temp1 = "", cont1 = "";
	while (m > 0)
	{
		if (m % 2 == 0)
		{
			temp1 += '0';
			m /= 2;
		} 
		else 
		{
			temp1 += '1';
			m--;
			m /= 2;
		}
	}
	for (int i = temp1.size() - 1; i >= 0; i--)
	{
		cont1 += temp1[i];
	}
	return cont1;
}
long long toten(string a)
{
	long long cont2 = 0;
	long long  mingci = 1;
	for (int i = a.size() - 1; i >= 0; i--)
	{
		cont2 += mingci * ((int)(a[i] - '0'));
//		cout << cont2 << ' ' << mingci << endl;
		mingci *= 2;
	}
	return cont2;
}
long long ad(string x, string y)
{
	long long len = max(x.size(), y.size());
	if (x.size() < y.size())
	{
		string use = x;
		x = "";
		for (int i = use.size() - 1; i < y.size() - 1; i++)
		{
			x += '0';
		}
		x += use;
	}
	else
	{
		string use = y;
		y = "";
		for (int i = use.size() - 1; i < x.size() - 1; i++)
		{
			y += '0';
		}
		y += use;
	}
	string temp3 = "";
	for (int i = 0; i < len; i++)
	{
		if (x[i] == '0' || y[i] == '0')
		{
			temp3 += '0';
		}
		else
		{
			temp3 += '1';
		}
	}
	return toten(temp3);
}
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &a[i]);
		as[i] = totwo(a[i]);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0 ;j < n; j++)
		{
			if(i != j)
			{
				maxx = max(maxx, ad(as[i], as[j]));
			}
			
		}
	}
	printf("%lld", maxx);
	return 0;
}
