#include <bits/stdc++.h>
using namespace std;
#define ll long long 
const int N = 2e5 + 7;
int n,m;

vector<ll> a(N);
set<int> st;

void solve(int x)
{
	int num = 0;
	set<int> stt;
	set<int> kk;
	vector<int> sum;
	for(int i=0;i<n;i++)
	{
		if(a[i] & (1<<x))
		{
			num ++;
			stt.insert(i);
		}
	}
//	cout<<"stt: ";
//	for(int j:stt) cout<<j<<" ";
//	cout<<endl;
//	cout<<"st: ";
//	for(int j:st) cout<<j<<" ";
//	cout<<endl;
	if(num >= m)
	{
		int cnt = 0;
		for(int j:stt)
		{
			if(st.count(j))
			{
				cnt++;
				kk.insert(j);
			}
		}
		if(st.empty())
		{
			for(int j:stt)
			{
				st.insert(j);
			}
			return ;
		}
		if(cnt >= m)
		{
			st.clear();
			for(int j:kk)
			{
		    	st.insert(j);
			}
			return ;
		}
	}
	return ;
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int i = 29;
	for(;i >= 0;i --)
	{
		solve(i);
	} 
	int ans = 1073741823;
	int cnt = 0;
	for(int j:st)
	{
		if(cnt < m)
		{
			ans &= a[j];
			cnt++;
		}
		else
		{
			break;
		}
	}
	
	if(ans != 1073741823)
	{
		cout<<ans<<endl;
	}
	else
	{
		cout<<0<<endl;
	}
	return 0;
}
/*
4 2
3 15 12 12

5 3
31 3 1 15 7
*/

