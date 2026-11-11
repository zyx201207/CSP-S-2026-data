#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],v[200005],maxn = -11111;
bool visited[200005];
void s(int death)
{
	if(death == m)
	{
		int cnt = 2147483647;
		for(int i = 0;i < death;i++)
		{
			cnt &= v[i];
		}
		maxn = max(maxn,cnt);
		return;
	}
	for(int i = 1;i <= n&&!visited[i];i++)
	{
		v[death] = a[i];
		visited[i] = 1;
		s(death+1);
		visited[i] = 0;
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >>m;
	for(int i = 1;i <= n;i++)
	{
		cin >>a[i];
	}
	s(0);
	cout<<maxn;
	return 0;
} 
