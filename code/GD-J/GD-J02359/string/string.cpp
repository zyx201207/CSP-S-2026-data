#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const int N = 2e5+5;
int n;
struct node{
	char c;
	int len;
}a[N];
ull ans = 0;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i].len >> a[i].c;
	}
	
	for(int i = 1,j = n;j > i;i++)
	{
		int num = a[i].len;
		while(num)
		{
			if(num >= a[j].len && a[i].c != a[j].c)
			{
				num -= a[j].len;
				ans += a[j--].len;
			}
			else if(num >= a[j].len && a[i].c == a[j].c)
			{
				num -= a[j--].len;
			}
			else if(num < a[j].len && a[i].c != a[j].c)
			{
				a[j].len -= num;
				ans += num; 
				num = 0;
			}
			else
			{
				a[j].len -= num;
				num = 0;
			}
		}
		//for(int k = 1;k <= n;k++)cout << a[k].len << " " << a[k].c << " ";cout << endl;
	}
	cout << ans;
	return 0;
}
