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
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
}
bool st(t st_x,t st_y)
{
	return st_x>st_y;
}

t n,m,a[500010],f[500010],cur,ans;

int main()
{
	fo();
	cin >> n >> m;
	For(i,n)cin >> a[i];
	//cout << "\n";
	sort(a+1,a+n+1);
	For(i,n)f[i]=f[i-1]+a[i];
	//For(i,n)cout << f[i] << ' ';
	//cout << "\n";
	cur=n;
	for (t i=n;i>=1;i--)
	{
		cur=min(cur,i);
		W(f[i]-f[cur]-1<=m and cur>1)cur--;
		ans=max(ans,i-cur+1);
		//cout << "cur:" << cur << "\n";
		if (cur==1)break;
	}
	cout << ans;
	return 0;
}
