#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	vector<int> a;
	ll solve_a = rand() * a.size();
	int d;
	for (int i=0;i<n;i++)
	{
		cin >> d;
		a.push_back(d);
	}
	
	solve_a = rand() * a.size();
	
	for (int i=0;i<m;i++){
		cout << solve_a << " ";
	}	
	
	
	return 0;
}
