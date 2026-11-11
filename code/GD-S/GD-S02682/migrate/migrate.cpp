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
void fo()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
}
bool st(t st_x,t st_y)
{
	return st_x>st_y;
}

t C,T,n,m,a[2000010],ans;

int main()
{
	fo();
	cin >> C >> T;
	For(box,T)
	{
		cin >> n >> m;
		ans=0;
		
		For(i,n)cin >> a[i];
		For(i,n-3)
		{
			for (t j=i+3;j<=n;j++)
			{
				if (a[j]-a[i+1]<=m and a[i+2]-a[i]<=m)ans++;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
