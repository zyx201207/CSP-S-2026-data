#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
typedef long long LL;
LL a[N], r[N], l; char c[N];
struct node{LL l, r; char c;};
vector<node> vec;
vector<LL> idx;
set<LL> st;
map<LL, bool> mp; 
LL n;
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (LL i = 1; i <= n; i++)
	{
		cin >> a[i] >> c[i];
		l += a[i];
		r[n - i + 1] = a[i];
	}
	//for (LL i = 1; i <= n; i++)
		//vec.push_back({s[i - 1] + 1, s[i], c[i]});

	LL pi = 1, pj = 1;
	for (LL i = 1, j = 1; i <= n and j <= n;)
	{
		//cout << pi << ' ' << pj << endl;
		mp[pi] = 1;
		if (pi == pj) {pi += a[i]; i ++;}
		else if (pi < pj) {pi += a[i]; i ++;}
		else if (pi > pj) {pj += r[j]; j ++;}
		st.insert(pi); st.insert(pj); 
	}
	mp[pi] = 1;
	//cout << pi << ' ' << pj << endl;
	for (auto i = st.begin(); i != st.end(); i++) idx.push_back(*i);
	char ch = c[1];
	LL col = 0;
	for (LL i = 0; i < idx.size() - 1; i++)
	{
		if (mp[idx[i]])ch = c[++col];
		vec.push_back({idx[i], idx[i+1]-1, ch});
	}
	//for (auto i : vec) cout << i.l << ' ' << i.r << ' ' << i.c << endl; 
	LL answer = 0;
	for (LL i = 0; i < (vec.size() / 2); i++)
	{
		if (vec[i].c != vec[vec.size() - i - 1].c) answer += (vec[i].r - vec[i].l + 1);
	}
	cout << answer;
	return 0;
 }
 /*
Part of my heart was left behind that day,
I remember everytime I smell the rain.
Asking myself what atonement means,
Why not this world takes me away, to heaven.
	from Petrichor - void(Mournfinale)
 */
