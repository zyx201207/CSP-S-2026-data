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
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
}
bool st(t x,t y)
{
	return x>y;
}

t n,m,a[200010],m2[35]={1},x=1,cnt[35],mx,ans,f[200010];
bool b[200010][35];
vector<t>wjq[35];

void ljh(t lv)
{
	t goal=-1;
//	for (t i=10;i>=0;i--)cout << cnt[i];
//	cout << "\n";
//	For(i,wjq[lv].size())
//	{
//		for (t j=10;j>=0;j--)cout << b[i][j];
//		cout << "\n";
//	}
//	cout << "\n";
	for (t i=lv;i>=0;i--)
	{
		if (cnt[i]>=m)
		{
			goal=i;
			break;
		}
	}
	//cout << lv << ' ' << goal << "|";
	//for (t i=lv;i>=0;i--)cout << cnt[i] << ' ';
	//cout << "\n";
	if (goal==-1)
	{
		cout << ans;
		return;
	}
	ans+=m2[goal];
	if (goal==0)
	{
		cout << ans;
		return;
	}
	t vs=wjq[lv].size(),member=0;
	_For(i,vs)
	{
		t zby=wjq[lv][i];
		if (b[zby][goal])
		{
			wjq[goal-1].push_back(zby);
			member++;
		}
		else
		{
			_For(j,f[zby]+1)
			{
				if (b[zby])cnt[j]--;
			}
		}
	}
	//cout << member << ' ';
	if (member<m)
	{
		cout << ans;
		return;
	}
	ljh(goal-1);
}

int main()
{
	fo();
	For(i,30)
	{
		x*=2;
		m2[i]=x;
	}
	cin >> n >> m;
	For(i,n)cin >> a[i];
	sort(a+1,a+n+1,st);
	For(i,n)
	{
		t tmp=a[i];
		for (t j=30;j>=0;j--)
		{
			if (a[i]>=m2[j])
			{
				a[i]-=m2[j];
				cnt[j]++;
				mx=max(mx,j);
				f[i]=max(f[i],j);
				b[i][j]=true;
			}
		}
		a[i]=tmp;
	}
	For(i,n)wjq[mx].push_back(i);
	ljh(mx);
}
