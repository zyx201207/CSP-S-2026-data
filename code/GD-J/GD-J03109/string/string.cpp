#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
#define int long long
int n;
int len[N];
char ch[N];
int sum_l = 0;
queue<pair<int, char> > q;
stack<pair<int, char> > st;
int lenl = 0, lenr = 0;

signed main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> len[i] >> ch[i], sum_l += len[i];
	int nw = 0;
	int tar = sum_l / 2;
	if(sum_l % 2 == 1)
	{
		for(int i = 1; i <= n; i++)
		{
			if(nw + len[i] > tar){
				len[i]--;
				sum_l--;
				break;
			}
			nw += len[i];
		}
	}
	nw = 0;
	for(int i = 1; i <= n; i++)
	{
		if(nw >= tar){
			st.push({len[i], ch[i]});
			nw += len[i];
		}
		else if(nw + len[i] > tar)
		{
			q.push({tar-nw, ch[i]});
			st.push({len[i] - tar + nw, ch[i]});
			nw += len[i];
//			cout << tar-nw << " " << ch[i] << " " << len[i] - tar + nw << " " << ch[i] << endl;
		}
		else{
			nw += len[i];
			q.push({len[i], ch[i]});
		}
//		cout << len[i] << " " << ch[i] << endl;
	}
	pair<int, char> l, r;
	int ans = 0;
	l = q.front(), r = st.top();
	q.pop(), st.pop();
	while(st.size() || q.size())
	{
		if(l.first < r.first)
		{
			if(l.second != r.second) ans += l.first;
			r.first -= l.first;
			l = q.front();
			q.pop();
		}
		else if(l.first > r.first)
		{
			if(l.second != r.second) ans += r.first;
			l.first -= r.first;
			r = st.top();
			st.pop();
		}
		else {
			if(l.second != r.second) ans += l.first;
			l = q.front();
			q.pop();
			r = st.top();
			st.pop(); 
		}
	}
	if(l.first || r.first)
	{
		if(l.first < r.first)
		{
			if(l.second != r.second) ans += l.first;
			r.first -= l.first;
		}
		else if(l.first > r.first)
		{
			if(l.second != r.second) ans += r.first;
			l.first -= r.first;
		}
		else {
			if(l.second != r.second) ans += l.first;
		}
	}
	cout << ans << endl;
}
