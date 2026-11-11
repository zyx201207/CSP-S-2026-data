#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	long long n,m;
	cin >> n >> m; 
	vector<long long> a(n);
	vector<long long> ans(m+1);
	for(int i=0;i<n;i++)
		cin >> a[i];
	for(int i=0;i<n;i++)
	{
		vector<int> sa(m+2);
		vector<long long> as;
		stack<long long> s;
		as=a;
		for(int l=i;l<n;l++)
		{
			if(sa[as[l]]>0)
			{
				while(s.size()>0)
				{
					if(s.top()==as[l])
						break;
					sa[s.top()]--;
					s.pop();
				}
			}
			else
			{
				sa[as[l]]++;
				s.push(as[l]);
			}
		}
		while(s.size()>0)
		{
			//cout << s.top() << ' ';
			ans[s.top()]++;
			s.pop();
		}
		//cout << endl;
	}
	for(int i=1;i<=m;i++)
		cout << ans[i] << ' ';
	return 0;
}
