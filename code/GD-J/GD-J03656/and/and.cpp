#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int> v(n);
	for(int i=0;i<n;i++)
	{
		int b;
		cin>>b;
		v.push_back(b);
	}
	sort(v.begin(),v.end(),cmp);
	cout<<v[m-1];
	return 0;
}
