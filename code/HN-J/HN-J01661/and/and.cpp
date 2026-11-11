#include<bits/stdc++.h> 
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m,k;
	cin>>n>>m;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	k=a[0];
	if(m==n)
	{
		for(int i=1;i<n;i++)
		{
			k=k&a[i];
		}
	}
	else if(m==1)
	{
		for(int i=1;i<n;i++) k=max(k,a[i]);
	}
	else if(m==2)
	{
		k=-1;
		for(int i=0;i<n-1;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				int x=a[i]&a[j];
				k=max(k,x);
			}
		}
	}
	else
	{
		vector<int> b;
		sort(a.begin(),a.end());
		for(int i=a.size()-1,j=0;j<m;j++,i--) b.push_back(a[i]);
		k=b[0];
		for(int i=1;i<m;i++) k=min(k,b[i]);
	}
	cout<<k;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
