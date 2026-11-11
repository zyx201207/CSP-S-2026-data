#include<iostream>
#include<vector>
using namespace std;
int cnt;
int df(vector<int> n)
{
	cnt--;
	if(cnt==0) 
	{
		int maxN=0;
		for(int i=0;i<n.size();i++)
		{
			maxN=max(maxN,n[i]);
		}
		return maxN;
	}
	vector<int> m;
	for(int i=0;i<n.size();i++)
	{
		for(int j=i+1;j<n.size();j++)
		{
			m.push_back(n[i]&n[j]);
		}
	}
	return df(m);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[200005],ans=0;
	cin>>n>>m;
	cnt=m;
	vector<int> s;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s.push_back(a[i]);
	}
	cout<<df(s);
	return 0; 
 } 
