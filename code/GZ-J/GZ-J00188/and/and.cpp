//准考证号：GZ-J00188 学校：遵义市新蒲新区滨湖中学  姓名：袁乙文
#include<iostream>
#include<cstdio>
#include<string> 
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
bool cmp(ll a,ll b)
{
	return a>b;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ll n,m;
	cin >> n >> m;
	vector<ll>a(n+10),ans(n+10);
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	sort(a.begin()+1,a.end());
	cout << a[1];
	
	return 0;
}
