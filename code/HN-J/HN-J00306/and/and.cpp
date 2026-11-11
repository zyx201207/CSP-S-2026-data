#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;
int arr[200005];
int findmax(int n)
{
	int maxn = -1;
	for (int i = 0;i < n;i++) 
	{
		if (arr[i] > maxn)
		{
			maxn = arr[i];
			arr[i] = 0;
		}
	}
	return maxn;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for (int i = 0;i < n;i++)
	{
		cin >> arr[i];
	}
	vector<int> v;
	for (int i = 0;i < m;i++)
	{
		v.push_back(findmax(n));
	}
	long long sum = v[0];
	for (int i = 0;i < v.size();i++)
	{
		sum &= v[i];
	}
	cout << sum;
	return 0;
 } 
