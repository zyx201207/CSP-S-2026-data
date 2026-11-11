//GZ-J00005 福泉中学 向治衡 
#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long n,m,num;
	cin>>n>>m;
	vector<long long>a(n);
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a.begin(),a.end(),greater<long long>());
	num=a[0];
	for(int i=1;i<m;i++)
	{
		num&=a[i];
	}
	cout<<num;
	return 0;
}
