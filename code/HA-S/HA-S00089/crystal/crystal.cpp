#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	int a,b;
	int d=0;
	cin>>a>>b;
	
	vector<int> v(a);
	//vector<long long> v1(a+1);
	
	
	
	for(int i=1;i<=a;i++)
	{
		cin>>v[i];
	}
	
	sort(v.begin(),v.end());
	/*
	for(int i=1;i<=a;i++)
	{
		v1[i]=v[i]+v1[i-1];
		cout<<v1[i]<<"\n";
	}*/
	
	int r=0,l=0;
	while(r<=a && r>=l)
	{
		int c=0;
		
		for(int j=l;j<r;j++)
		{
			c+=v[r]-v[j];
		}
		if(c>b)
		{
			l++;
		}
		else
		{
			d=max(d,r-l);
			
			
		}
		//cout<<l<<" "<<r<<" "<<c<<" "<<r-l<<"\n";
		r++;
		
	}
	
	
	/*
	for(int i=0;i<v[v.size()-1];i++)
	{
		int c=0;
		for(int j=0;j<i;j++)
		{
			c+=v[j]-v[i];
		}
		if(abs(c)>b)
		{
			break;
		}
		else
		{
			d=i+1;
		}
	}
	*/
	cout<<d;
	
	return 0;
}
