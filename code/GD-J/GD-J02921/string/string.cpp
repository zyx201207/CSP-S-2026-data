#include <bits/stdc++.h>
#define s string
#define t long long
#define d double
#define c char
#define For(a,b) for (t a=1;a<=b;a++)
#define _For(a,b) for (t a=0;a<b;a++)
#define W(a) while(a)
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
const t e9=1e9,e18=1e18;
void fo()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
}
bool st(t x,t y)
{
	return x>y;
}

t n,m,ln,ans,lcur,rcur,f[200010],rcur2,last;
c b;
struct tt
{
	t cnt;
	c a;
}a[200010];

int main()
{
	fo();
	cin >> n;
	For(i,n)
	{
		cin >> a[i].cnt >> a[i].a;
		ln+=a[i].cnt;
	}
	For(i,n)f[i]=f[i-1]+a[i].cnt;
	rcur=n;
	rcur2=f[n];
	last=n;
//	For(i,n)cout << f[i] << ' ';
//	cout << "\n"; 
	For(i,n)
	{
		lcur=min(f[i],ln/2);
		W(rcur2>ln-lcur)
		{
			t tmp=rcur2;
			if (f[rcur-1]>ln-lcur)
			{
				rcur2=f[rcur-1];
				if (a[rcur].a!=a[i].a)ans+=tmp-rcur2;
				//cout << tmp << '-' << rcur2 << '{' << rcur << '-' << i << '}';
				rcur--;
			}
			else
			{
				rcur2=ln-lcur;
				if (a[rcur].a!=a[i].a)ans+=tmp-rcur2;
			}
			//cout << "i:" << i << ' ' << "lcur:" << lcur << ' ' << "rcur:" << rcur2 << ' ';
			//cout << "rcurp:" << rcur << ' ' << "ans:" << ans << ' ' << "tmp:" << tmp << "\n";
		}
		last=i;
	}
	//if (a[last].a!=a[rcur].a)ans++;
	cout << ans;
}
