#include<bits/stdc++.h>
using namespace std;
long long s,n,a[2000001],d,s1;
string b[2000001];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		s+=a[i];
	}
	d=s/2;
	long long t=n,t1=1;
	for(int i=1;;i++)
	{
		if(d>a[t1]&&a[t1]>a[t])
		{
			d-=a[t];
			if(b[t1]!=b[t])
				s1+=a[t]; 
			a[t1]-=a[t];
			t-=1;
		}
		else if(d<=a[t1]&&d>a[t])
		{
			d-=a[t];
			a[t1]-=a[t];
			if(b[t1]!=b[t])
				s1+=a[t]; 
			t-=1;
		}
		else if(d<=a[t1]&&d<=a[t])
		{
			d=0;
			if(b[t1]!=b[t])
				s1+=min(a[t],a[t1]); 
			t-=1;
		}
		else if(d>a[t1]&&a[t1]<=a[t])
		{
			d-=a[t1];
			a[t]-=a[t1];
			if(b[t1]!=b[t])
				s1+=a[t1]; 
			t1++;
		}
		if(d==0)
			break;
	}	
	cout<<s1;
	return 0;
}
