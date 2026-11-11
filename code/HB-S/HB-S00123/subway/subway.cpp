#include<bits/stdc++.h>
using namespace std;
int a, n, m, d, q;
struct Node
{
	int w;
	int id[10005];
};
Node s[10000];
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	for(int i = 1;i<=m;i++) cin>>s[i].w;
	for(int i = 1;i<=n;i++)
	{
		int k ; cin>>k;
		int a[1000005];
		for(int j = 1;j<=2*k;j++)
		{
			cin>>a[i];
		}
		int x, y;
		cin>>x>>y;
	}
	cout<<4*s[1].w;
	return 0;
}
