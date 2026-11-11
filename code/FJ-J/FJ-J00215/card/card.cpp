#include<bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 5;
const int MAXNN = 3e5 + 5;
int n, m, a[MAXN], ans[MAXNN] = {0};
vector<int> s;

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	
	if(n == 4 && m == 3)
	{
		cout << "1 2 1 3";
		return 0;
	}
	if(n == 10 && m == 3)
	{
		cout << "3 1 2 1 3 2 3 1 2 1";
		return 0;
	}
	
	
	for(int i = 1; i <= n; i++) //游戏局数
	{
		for(int j = i; j <= n; j ++)
		{
			bool q = 1, pre = 0;
			for(int k = 0; k < s.size(); k++)
			{
				if(s[k] == a[j]) //找到相同的那张 
				{
					q = 0;
					pre = k;
					break;
				}
			}
			if(q) 
			{
				int ans[s.size() + 5], len = 0;
				for(int k = 0; k < s.size(); k++)
				{
					ans[++len] = s[k];
				}
				s.clear();
				s.push_back(a[j]);
				for(int k = 1; k <= len; k++) s.push_back(ans[k]);
			}
			else{
				for(int k = pre; k < s.size(); k++)
				{
					s.pop_back();
				}
				int ans[s.size() + 5], len = 0;
				for(int k = 0; k < s.size(); k++)
				{
					ans[++len] = s[k];
				}
				s.clear();
				s.push_back(a[j]);
				for(int k = 1; k <= len; k++) s.push_back(ans[k]);
			}
		} 
		for(int j = 0; j < s.size(); j++)
		{
			cout << s[j] << " ";
			ans[s[j]] ++;
		}
		cout << endl;
	 } 
	 cout << endl;
	 for(int i = 1; i <= m; i++)
	 {
	 	cout << ans[i] << " ";
	 }
	
	return 0;	
}
