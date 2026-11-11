#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,z;
int a[1000];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i = 0;i < m;i++)
	{
		scanf("%d",&z);
		a[i] = z;
	}
	for(int i = 0;i < n;i++)
	{
		cout << q << endl;
	}
	return 0;
}
