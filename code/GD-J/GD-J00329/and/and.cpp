#include<bits/stdc++.h>
using namespace std;
long long a[100000000];
int n,m;
int e=1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","out",stdout);
	cin>>n>>m;
	int maxxx=-1;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]>maxxx) maxxx=a[i];
		if(a[i]!=i-1) e=0;
	}
	int ans=a[0];
	for(int i=1;i<n;i++)
	{
		ans=ans&a[i];
	}
	if(m==n)
	{
		cout<<ans;
		return 0;
	}
	int maxx=-1;
	if(m==1)
	{
		cout<<maxxx;
	}
	else if(m==2)
	{
		for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			int t=a[i]&a[j];
			if(maxx<t) maxx=t;
		}
	}
	cout<<maxx;
	}
	else if(m==3)
	{
		for(int i=0;i<n-2;i++)
	{
		for(int j=i+1;j<n-1;j++)
		{
			for(int z=j+1;z<n;z++){
				int t=a[i]&a[j]&a[z];
			    if(maxx<t) maxx=t;
			}
			
		}
	}
	cout<<maxx;
	}
	else if(m==n-1)
	{   int t=a[1];
	    for(int i=2;i<n;i++) 
	    {
	    	t=t&a[i];
		}
		if(maxx<t) maxx=t;
		t=a[0];
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(j==i) continue;
				t=t&a[j];
			}
			if(maxx<t) maxx=t;
			t=a[0];
		}
		cout<<maxx;
	}
	else if(e==1)
	{
		cout<<n-3;
		return 0;
	}
}
