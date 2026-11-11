#include <iostream>
#include <cstdio> 
using namespace std;

long long ans , len , pl , ql , pn , qn;
int n , a[1000000] , i , j;
char c[1000000];
int p , q;
bool pe , qe;

int main()
{
	freopen("string.in" , "r" , stdin);
	freopen("string.out" , "w" , stdout);
	cin >> n;
	for (int i = 0 ; i < n ; i++)
	{
		cin >> a[i] >> c[i];
		len += a[i];
	}
	p = 0; q = n - 1;
	while (!pe || !qe) 
	{
		if (pn == 0 && !pe) //p到下一个 
		{
			if(pl + a[p] >= len / 2)
			{
				pe = 1;
				pn = len / 2 - pl;
			}
			else 
			{
				pn = a[p];
				pl += a[p];
			}
		}
		if (qn == 0 && !qe) //q到下一个 
		{
			if(ql + a[q] >= len / 2)
			{
				qe = 1;
				qn = len / 2 - ql;
			}
			else 
			{
				qn = a[q];
				ql += a[q];
			}
		}
		long long t = min(qn , pn);
		if(c[p] != c[q]) ans += t;
		qn -= t;
		pn -= t;
		if(qn == 0)q--;
		if(pn == 0)p++;
		//cout << p <<' ' << pn << "|" << q << ' ' << qn << endl;
		
	}
	cout << ans;
	return 0;
} 
