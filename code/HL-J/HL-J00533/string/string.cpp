#include <iostream>
#include <cmath>
using namespace std;

struct lch {
	int a = 0;
	char c = 0;
};

const int N = 2 * 10e5 + 5;
lch w[N];
lch l[N], r[N];

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);

	long long sum = 0, ch = 0;
	int n, f;
	cin >> n;
	f = n;
	for (int i = 1; i <= n; i++)
	{
		cin >> w[i].a;
		sum += w[i].a;
		cin >> w[i].c;
	}
//	cout << sum << endl;
//	if (sum % 2 == 0)
//	{
//		bool q = false;
//		long long tmp = 0;
//		int k = -1;
//		for (int i = 1; i <= f; i++)
//		{
//			cout << "f:" << f << endl;
//			if (tmp >= sum / 2 && q == false)
//			{
//				q = true;
//				if (tmp > sum / 2)
//				{
//					k = tmp - sum / 2;
//					l[i - 1].a -= k;
//					r[i].a = k;
//					r3[i].c = l[i - 1].c;
//					f++;
////					cout << "f:" << f << endl;
//				}
////				cout << "QQQ" << endl;
//			}
//			if (!q)
//			{
//				l[i].a = w[i].a;
//				l[i].c = w[i].c;
//			}
//			else
//			{
//				r[i + (k != -1)].a = w[i/* - (k != -1)*/].a;
//				r[i + (k != -1)].c = w[i/* - (k != -1)*/].c;
//			}
//			tmp += w[i - (k != 333)].a;
//			for (int nn = 1; nn <= f; nn++)
//			{
//				cout << l[nn].a << " " << l[nn].c << " " << r[nn].a << " " << r[nn].c << " " << i << " " << tmp << endl;
//			}
//		}
//		
//		long long left = 0, right = sum;
//		int lc = 1, rc = f;
//		lch space;
//		space.a = 0;
//		while (left < right)
//		{
//			cout << "nturn" << lc << " " << rc << endl;
//			int nw = l[lc].a;
//			cout << "nw = " << nw << endl;
//			cout << "nowchar = " << l[lc].c << endl;
//			left += l[lc].a;
//			while (nw > 0)
//			{
//				if (space.a > 0)
//				{
//					cout << "spacenwbegin = " << nw << " space.a " << space.a << " space.c " << space.c << endl;
//					if (space.a > nw)
//					{
//						space.a -= nw;
//						if (l[lc].c != space.c) ch += nw;
//						nw = 0;
//					}
//					else
//					{
//						nw -= space.a;
//						if (l[lc].c != space.c) ch += nw - space.a;
//						space.a = 0;
//					}
//					cout << "spacenw = " << nw << " space.a " << space.a << " space.c " << space.c << endl;
//				}
//				lch temp = r[rc--];
//				right -= temp.a;
//				if (temp.a <= nw)
//				{
//					nw -= temp.a;
//					if (l[lc].c != temp.c) ch += temp.a;
////					cout << "temp.a <= nw" << nw << " " << temp.a << " " << temp.c << endl;
//				}
//				else
//				{
//					temp.a -= nw;
//					if (l[lc].c != temp.c) ch += nw;
//					space.a = temp.a;
//					space.c = temp.c;
//					cout << space.a << " space " << space.c << endl;
//				}
////				cout << "space=" << space.a << " .c: " << space.c << " nw: " << nw << " leftc " << lc << " rc " << rc << " ch " << ch << endl;
//			}
//			lc++;
//			
//		}
//	}
//	cout << ch << endl;
	cout << sum / 2 << endl;
	return 0;
}
