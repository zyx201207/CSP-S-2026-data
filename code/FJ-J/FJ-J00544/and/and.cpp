#include <bits/stdc++.h>
using namespace std;
string a[200005];
int maxn = 0;

bool cmp(string a, string b)
{
	return a > b;
}

int main ()
{
	//freopen("and.in", "r", stdin);
	//freopen("and.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
    	long long x;
    	cin >> x;
    	int pos = 0;
    	string o = "";
    	while(x)
    	{
    		if(x%2 == 0) o+='0';
    		else o+='1';
    		x/=2;
		}
		reverse(o.begin(), o.end());
		maxn = max(maxn, (int)o.size());
		a[i] = o;
	}
	//cout <<1;
	for(int i = 1;i <= n;i++)
	{
		if((int)a[i].size() < maxn)
		{
			reverse(a[i].begin(), a[i].end());
			while(a[i].size()<maxn)
			{
				a[i]+='0';
			}
			reverse(a[i].begin(), a[i].end());
		}
	}
	sort(a+1, a+n+1, cmp);
	long long maxn;
	/*for(int i = 1;i <= n;i++)
	{
		cout << a[i]<<" ";
	}*/
	for(int i = 1;i <= m;i++)
	{
		long long d = 0, pos = a[i].size()-1, quan = 1;
		while(pos>=0)
		{
			if(a[i][pos] == '1') d+=quan;
			pos--;
			quan*=2;
		}
		//cout << d << '\n';
		if(i == 1)
		{
			maxn = d;
		}
		else maxn = maxn&d;
	}
	cout << maxn;
	return 0;
}
