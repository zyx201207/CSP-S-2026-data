#include <bits/stdc++.h>
using namespace std;
string a[100005];
int main()
{
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
	long long n;
	cin >> n;
	long long t = 0, t2 = 0, t3 = 0;
	for(int i = 1; i <= n; i++)
	{
		
		int s1, s2;
		cin >> s1 >> s2;
		for(int j = s1; j >= 1; j--)
		{
			t++;
			a[t]={s2};
		}
	}
	t3 = t / 2;
	for(int x = 0; x <= t3; x++)
	{
		if(a[x + 1] != a[t - x])
		{
			t2++;
		}	
	} 
	cout << t2;
	
	return 0;
}
