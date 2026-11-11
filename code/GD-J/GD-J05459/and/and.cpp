#include<iostream>
using namespace std;
int n,m,maxn = 0; 
int a[200010];
void cal(int step,int last,int sum)
{
	if(step > m)
	{
		maxn = max(maxn,sum);
	}
	for(int i = last + 1;i <= n;i++)
	{
		if(step == 1) cal(step + 1,i,a[i]);
		else cal(step + 1,i,sum & a[i]);
	}
}
int main()
{
	int maxn = -1e9;
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	cal(1,0,0);
	cout << maxn << endl;
	return 0;
}
