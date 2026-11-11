#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,max=0;
	cin>>n>>m;
	vector<long long> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a.begin(),a.end());
	if(m==1) cout<<a[a.size()-1];
	else if(m==2)
	{
		for(int i=a.size()-1;i>0;i--)
		{
			if(a[i]&a[i-1]>max) max=a[i]&a[i-1];
		}
		cout<<max;
	}
	else if(m==n)
	{
		max=a[0];
		for(int i=1;i<n;i++)
		{
			max=max&a[i];
		}
		cout<<max;
	}
	return 0;
}
