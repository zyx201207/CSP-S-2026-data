#include<bits/stdc++.h>
using namespace std;
const int N = 2 * 1e5;
struct node
{
	long long num,cnt;
	string s;
}arr[N];
long long n,m;
long long vis[31];
bool cmp(node a,node b)
{
	if(a.cnt != b.cnt) return a.cnt > b.cnt;
	return a.num > b.num;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> arr[i].num;
		int j = arr[i].num,cn = 0;
		string ss = "";
		while(j)
		{
			if(j % 2 == 1) cn++;
			ss += j % 2 + '0';
			j /= 2;
		}
		arr[i].cnt = cn; 
		reverse(ss.begin(),ss.end());
		arr[i].s = ss;
	}
	sort(arr + 1,arr + 1 + n,cmp);
	long long ans = 0;
	for(int i = 1;i <= m;i++)
	{
		if(ans == 0) ans = arr[i].num;
		else ans = ans & arr[i].num;
	}
	cout << ans;
	return 0;
}
