#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int>a(n),big;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a.begin(),a.end());
	int sum=a[a.size()-1];
	int cnt=a.size()-2;
	for(int i=0;i<m-1;i++)
	{
		sum&=a[cnt];
		cnt--;
	}
	cout<<sum;
	return 0;
}
