#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,mx=0,ai=0;
	cin>>n>>m;
	vector<int>a;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		a.push_back(x);
	}
	if(m==1)
	{
		mx=a[0];
		for(int i=1;i<n;i++)
			mx=max(a[i],mx);
		cout<<mx<<'\n';
		return 0;
	}
	else if(m==2)
	{
		mx=a[0]&a[1];
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++)
				mx=max(mx,a[i]&a[j]);
		cout<<mx<<'\n';
		return 0;
	}
	else if(m==n)
	{
		mx=a[0]; 
		for(int i=0;i<n;i++)
			mx&=a[i];
		cout<<mx<<'\n';
		return 0;
	}
	mx=a[0];
	for(int i=0;i<n;i++)
	{
		if(a[i]>mx)
		{
			ai=i;
			mx=a[i];
		}
	}
	a.erase(a.begin()+ai,a.begin()+ai+1);
	m--;
	while(m>0)
	{
		int ii=0;
		for(int i=0;i<a.size();i++)
			if(mx&a[ii]<mx&a[i])
				ii=i;
		mx&=a[ii];
		a.erase(a.begin()+ii,a.begin()+ii+1);
		m--;
	}
	cout<<mx<<'\n';
	return 0;
}
