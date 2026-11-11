#include <bits/stdc++.h>
using namespace std;
int n;
long long num[200005],nsum,idx,nowa,nowb,ans;
char c[200005];
/*/
判断每个位置是否相等即可。 
/*/
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> num[i] >> c[i];
		nsum += num[i];
	}
	long long res = 0;
	if (nsum % 2)
	{
		for (int i = 1;i <= n;i++)
		{
			res += num[i];
			if (res >= (nsum + 1) / 2)
			{
				num[i]--;
				nsum--;
				break ;
			}
		}
	}
	res = 0;
	for (int i = 1;i <= n;i++)
	{
		res += num[i];
		if (res > nsum / 2)
		{
			for (int j = n;j > i;j--)
			{
				num[j + 1] = num[j];
				c[j + 1] = c[j];
			}
			n++;
			num[i + 1] = res - nsum / 2;
			num[i] -= num[i + 1];
			c[i + 1] = c[i];	
			nowa = i;
			nowb = i + 1;
			break ;
		}
		else if (res == (nsum + 1) / 2)
		{
			nowa = i;
			nowb = i + 1;			
			break;
		}
	}
//	for (int i = 1;i <= n;i++)
//	{
//		cout << num[i] << c[i] << ' ';
//	}
//	cout << endl << nowa << ' ' << nowb << endl;
	while (1)
	{
		long long minn = min(num[nowa],num[nowb]);
		ans += minn * (c[nowa] != c[nowb]);
		num[nowa] -= minn;
		num[nowb] -= minn;
		if (nowa == 1 && nowb == n)
		{
			break;
		}
		nowa -= !num[nowa];
		nowb += !num[nowb];
	}
	cout << ans << endl;
	return 0;
}

