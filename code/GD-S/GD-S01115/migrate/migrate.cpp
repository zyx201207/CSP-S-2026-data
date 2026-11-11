#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin >> c >> t;
	while(t--)
	{
		int n;//岛屿数量
		vector<int>a (n) ;
		int d;//鸟一次能飞的最远距离
		cin >> n >> d;
		for(int i = 0; i < n; i++)//输入 
			cin >> a[i];
		int geshu = n-d-1;
		int num = geshu/d;
		int sum = geshu%d;
		int ans = num+sum;
		cout << ans << endl;	
	}
	return 0;
}
