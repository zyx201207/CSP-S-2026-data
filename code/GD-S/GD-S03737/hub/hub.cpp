#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,k;
int a[2][1000],num = 0,b[1000];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	scanf("%d%d",&c,&t);
	for(int i = 0;i < t;i++)
	{ 
		scanf("%d%d",&n,&k);
		int x,y;
		for(int j = 0;j < n;j++)
		{
			scanf("%d%d",&x,&y);
			a[0][j] = x;
			a[1][j] = y;
		}
		b[i] = num;
	}
	for(int i = 0;i < t;i++)
	{
		cout << b[i] << endl;
	}
	return 0;
}
