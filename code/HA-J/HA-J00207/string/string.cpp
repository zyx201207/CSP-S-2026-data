#include <bits/stdc++.h>
using namespace std ;

const int N = 2e5 + 10 ;
long long n , cnta , cntb , sum , posa , posb , res , ida = 1 , idb = 1 , suma , sumb ;
bool flag ;

struct Node
{
	long long cnt ;
	char ch ;
} a [N] , b [N] , c [N] , tmpp [N] ;
int main ()
{
	freopen ("string.in" , "r" , stdin) ;
	freopen ("string.out" , "w" , stdout) ;
	ios :: sync_with_stdio (0) ;
	cin . tie (0) ;
	cout . tie (0) ;
	cin >> n ;
	for (int i = 1 ; i <= n ; i ++)
	{
		cin >> c [i] . cnt >> c [i] . ch ;
		sum += c [i] . cnt ;
	}
	long long tmp = 0 ;
	for (int i = 1 ; i <= n ; i ++)
	{
		if (tmp + c [i] . cnt <= sum / 2 && ! flag)
		{
			tmp += c [i] . cnt ;
			cnta ++ ;
			a [cnta] . cnt = c [i] . cnt ;
			a [cnta] . ch = c [i] . ch ;
		}
		else
		{
			if (! flag)
			{
				flag = true ;
				cnta ++ ;
				a [cnta] . ch = c [i] . ch ;
				tmpp [cntb] . ch = c [i] . ch ;
				if (sum % 2 == 1)
				{
					a [cnta] . cnt = sum / 2 - tmp ;
					if (c [i] . cnt - (sum / 2 - tmp) - 1 == 0)
						continue ;
					cntb ++ ;
					tmpp [cntb] . ch = c [i] . ch ;
					tmpp [cntb] . cnt = c [i] . cnt - (sum / 2 - tmp) - 1 ;
				}
				else
				{
					a [cnta] . cnt = sum / 2 - tmp ;
					if (c [i] . cnt - (sum / 2 - tmp) == 0)
						continue ;
					cntb ++ ;
					tmpp [cntb] . ch = c [i] . ch ;
					tmpp [cntb] . cnt = c [i] . cnt - (sum / 2 - tmp) ;
				}
			}
			else
			{
				cntb ++ ;
				tmpp [cntb] . cnt = c [i] . cnt ;
				tmpp [cntb] . ch = c [i] . ch ;
			}
		}
	}
	for (int i = cntb ; i >= 1 ; i --)
		b [cntb - i + 1] = tmpp [i] ;
	for (int i = 1 ; i <= cnta ; i ++)
		suma += a [i] . cnt ;
	for (int i = 1 ; i <= cntb ; i ++)
		sumb += b [i] . cnt ;
//	for (int i = 1 ; i <= cnta ; i ++)
//		cout << a [i] . cnt << a [i] . ch << " " ;
//	cout << "\n" ;
//	for (int i = 1 ; i <= cntb ; i ++)
//		cout << b [i] . cnt << b [i] . ch << " " ;
//	cout << "\n" ;
	//	cout << cnta << " " << cntb << " " << a [cnta] . cnt << " " << b [cntb] . cnt << "\n" ;
	while (true)
	{
//		if ((ida == cnta && posa == a [ida] . cnt) && (idb == cntb && posb == b [idb] . cnt))
//			break ;
		if (ida > cnta && idb > cntb)
			break ;
		long long yidong = min (a [ida] . cnt - posa , b [idb] . cnt - posb) ;
		posa += yidong ;
		posb += yidong ;
		if (a [ida] . ch != b [idb] . ch)
			res += yidong ;
		if (posa == a [ida] . cnt)
			ida ++ , posa = 0 ;
		if (posb == b [idb] . cnt)
			idb ++ , posb = 0 ;
//		cout << "本次移动，距离为" << yidong << "，最终 posa=" << posa << "，posb=" << posb << "，ida=" << ida << "，idb=" << idb << endl ;
//		if ((ida == cnta && posa == a [ida] . cnt) && (idb != cntb || posb != b [idb] . cnt))
//		{
//			res += b [idb] - pos [i] ;
//		}
//		cout << res << "\n" ;
	}
	cout << res ;
	return 0 ;
}
/*
3
5 a
5 b
5 c
1000000000

5
3 a
1 a
4 b
2 c
5 a
*/
