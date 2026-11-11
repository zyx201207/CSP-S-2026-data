#include <iostream>
#include <cstdio>

using namespace std;

int n, a[200005], cha,ai,aj, ma, mi, bl = 0;
long long all, ans = 0;
char c[200005], y;

int main()
{
	freopen("string.in","r" ,stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i] >> c[i];
		all += a[i];
	}
	int i = 1 ,j = n;
	ai = a[i], aj = a[j];
	//cout << all << endl;
	while (all / 2 >= bl || i == j)
	{
		cha = max(ai, aj) - min(ai, aj);
		ma = max(ai, aj);
		mi = min(ai, aj);
		bl += mi;
		
		if (all / 2 < bl)  break;
		
		if (c[i] != c[j])
		{
			ans += mi;
		}
		
		if (ai > aj)
		{
			j--;
			aj = a[j];
			ai = cha;
		}
		else if(ai < aj)
		{
			i++;
			ai = a[i];
			aj = cha;
		}
		else
		{
			i++;
			ai = a[i];
			j--;
			aj = a[j];
		}
		/*cout << "ai " << ai << endl;
		cout << "aj " << aj << endl;
		cout << "i " << i << endl;
		cout << "j " << j << endl;
		cout << "cha " << cha << endl;
		cout << "ma " << ma << endl;
		cout << "mi " << mi << endl;
		cout << "ans " << ans << endl;*/
	}
	cout << ans << endl;
	return 0;
}
