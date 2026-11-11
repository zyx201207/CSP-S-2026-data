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
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
}
bool st(t x,t y)
{
	return x>y;
}

t n,m,a[500010],cur[300010],pnt,cs[500010],cnt[300010];
//t n,m,a[500010],cur[300010],cnt;

int main()
{
	fo();
	cin >> n >> m;
	For(i,n)cin >> a[i];
	For(i,n)
	{
		pnt=0;
		for (t j=i;j<=n;j++)
		{
			pnt++;
			cs[pnt]=a[j];
			//cout << cur[cs[pnt]] << ' ';
			if (cur[a[j]]>0 and cs[cur[a[j]]] and cur[a[j]]<pnt)pnt=cur[a[j]];
			cur[a[j]]=pnt;
		}
//		cout << '|';
//		For(j,pnt)cout << cs[j] << ' ';
//		cout << "\n";
		For(j,pnt)
		{
			cnt[cs[j]]++;
			cur[cs[j]]=0;
			cs[j]=0;
		}
		pnt=0;
		mem(cs,0);
		mem(cur,0);
	}
	For(i,m)cout << cnt[i] << ' ';
//	for (t i=n;i>=1;i--)
//	{
//		if (cur[a[i]]==0)cur[a[i]]=i;
//		else
//		{
//			l=min(l,i);
//			r=max(r,cur[a[i]]);
//		}
//	}
}
