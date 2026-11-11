#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 205000;
ll n, m, i, j, k, idx=0,ls,rs,ans, hi, ma=0, x,sz,cnt;
ll a[N];
ll flag = 0;
vector<int> v,tv;
vector<int> r,tr;
int main()
{
//	cout << (15 & 8);
//	int task = 9178;
//	string filename = "and"+to_string(task)+".in";
//	freopen(filename.c_str(),"r",stdin);
//	cout << filename << endl;
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	cin >> n >> m;
	ma = 0;
	for (i=1; i<=n; i++)
	{
		cin >> a[i];
		v.push_back(a[i]);
		r.push_back(i);
		ma = max(ma, a[i]); 
	}
	hi = log2(ma);
	for (i=hi; i>=0; i--)
	{
		x = 1ll << i;
//		cout << x << endl;
		tv.clear();tr.clear();
		sz = v.size();
		for (j=0; j<sz; j++)
		{
			if ((x & v[j]) != 0ll)
			{
				tv.push_back(v[j]);
				tr.push_back(r[j]);
			}
		}
		sz = tv.size();
		if (sz >= m)
		{
			v = tv;
			r = tr;
		}
	}
//	cout << v.size() << endl << r.size()<<endl;
	sz = r.size();
//	for (auto it : r) cout << it << " ";
//	cout << endl;
//	cout << sz << endl;
	if (sz>=1)
	{
		ans = a[r[0]];
//		cout << ans << endl;
		for (i=1; i<sz; i++)
			ans = ans & a[r[i]];
		cout << ans;
	}
	else cout << 0;
	fclose(stdin);fclose(stdout);
	return 0;
}
/*
if (flag == 0)
		{
			x = 1ll << i;
			 for (j=1; j<=n ;j++)
			 {
			 	if (a[j] & x != 0)
			 	{
			 		v[i].push_back(a[j]);
			 		r[i].push_back(j);
				 }
			 }
			 if (v[i].size() >= m)
			 {
			 	flag = 1;
			 	ans += x;
			 }
		}else{
			x = 1ll << i;
			for (auto vv : v[i+1])
			{
				if (vv & x != 0)
				{
					v[i].push_back(vv);
				 } 
			} 
			if (v[i].size() >= m)
			{
				ans += x;
			}else{
				break;
			}
		}

*/


