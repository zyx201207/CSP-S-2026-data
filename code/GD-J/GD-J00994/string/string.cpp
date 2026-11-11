#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;
ll n,a[N],ans,len,nwa[N],nwcnt,idx,pre,l,r,lef,rig;
char c[N],nwc[N];
void solve()
{
	while (l >= 1 && r <= n)
	{
//		cout << l << ' ' << r << ' ' << lef << ' ' << rig << endl;
		if (lef > rig)
		{
			if (nwc[l] != nwc[r]) ans += rig;
			lef -= rig;
			r++;
			rig = nwa[r];
		}
		else if (lef < rig)
		{
			if (nwc[l] != nwc[r]) ans += lef;
			rig -= lef;
			l--;
			lef = nwa[l];
		}
		else
		{
			if (nwc[l] != nwc[r]) ans += lef;
			l--,r++;
			lef = nwa[l],rig = nwa[r];
		}
	}
//	cout << l << ' ' << r << ' ' << lef << ' ' << rig << endl;
	cout << ans;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) 
	{
		cin >> a[i] >> c[i];
		len += a[i];
	}
	nwa[++nwcnt] = a[1];
	nwc[nwcnt] = c[1];
	for (int i = 2; i <= n; i++)
	{
		if (c[i] == nwc[nwcnt]) nwa[nwcnt] += a[i];
		else nwa[++nwcnt] = a[i],nwc[nwcnt] = c[i];
	}
//	for (int i = 1; i <= nwcnt; i++) cout << nwa[i] << ' ' << nwc[i] << endl;
	for (int i = 1; i <= nwcnt; i++)
	{
		pre += nwa[i];
		idx = i;
//		cout << pre << endl;
		if (pre >= (len + 1) / 2) break;
	}
	if (pre == len / 2 && len % 2 == 0) 
	{
		l = idx,r = idx + 1;
		lef = nwa[l],rig = nwa[r];
	}
	else
	{
		if (len % 2 == 0)
		{
			l = idx,r = idx;
			rig = pre - len / 2;
			lef = nwa[l] - rig;
			if (lef < rig) rig -= lef,l--,lef = nwa[l];
			else if (lef > rig) lef -= rig,r++,rig = nwa[r];
			else l--,r++,lef = nwa[l],rig = nwa[r];
		}
		else
		{
			l = idx,r = idx;
			rig = pre - (len + 1) / 2;
			lef = nwa[l] - rig - 1;
			if (lef == 0) 
			{
				l--;
				lef = nwa[l];
			}
			if (rig == 0)
			{
				r++;
				rig = nwa[r];
			}
		}
	}
//	cout << idx << endl;
//	cout << l << ' ' << lef << ' ' << r << ' ' << rig << endl;
	solve();
	return 0;
}
/*
3
2 a
2 b
1 c

2
2 a
3 a

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
