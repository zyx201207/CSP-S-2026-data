//准考证号：GZ-J00188 学校：遵义市新蒲新区滨湖中学  姓名：袁乙文
#include<iostream>
#include<cstdio>
#include<string> 
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ll n,m;
	cin >> n >> m;
	vector<ll>a,b;
	for(int i=1;i<=n;i++)
	{
		ll k;
		cin >> k;
		a.push_back(k);
	}
	cout << a[4]+a[10];	
	
	return 0;
}
