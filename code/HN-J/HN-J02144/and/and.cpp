#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	vector<ll> sm;
	int d;
	for (int i=0;i<n;i++){
		cin >> d;
		sm.push_back(d);
	}
	
	ll solve_a = rand() * sm.size();
	cout << solve_a;
	
	
	return 0;
}
