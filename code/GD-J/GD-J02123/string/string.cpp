#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a[200005],s=0;
	char b[200005];
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>b[i];
	bool f=0;
	for(int i=1;i<n;i++)
	{
		if(b[i]!=b[i+1]) f=1;
	}
	if(f==0){cout<<0; return 0;}
	for(int i=1,j=n;i<=j;i++,j--)
	{
		while(a[i]<=0)
		{
			if(a[i]!=0) a[i+1]=a[i+1]-abs(a[i]);
			a[i]=0;
			i++;
			if(i==j) break;
		}
		while(a[j]<=0)
		{
			if(a[j]!=0) a[j-1]=a[j-1]-abs(a[j]);
			a[j]=0;
			j--;
			if(i==j) break;
		}
		if(a[i]!=a[j])
		{
			if(b[i]==b[j]) 
			{
				if(a[i]>a[j]&&b[i+1]==b[i])
				{
					s=s+(a[i]-a[j]);
					a[i+1]=a[i+1]+(a[i]-a[j]);
				}
				if(a[i]<a[j]&&b[j]==b[j-1])
				{
					s=s+(a[i]-a[j]);
					a[i+1]=a[i+1]+(a[i]-a[j]);
				}
				else 
				{
					s+=abs(a[i]-a[j]);
					if(a[i]>a[j]) a[j-1]=a[j-1]-(a[i]-a[j]);
					else a[i+1]=a[i+1]-(a[j]-a[i]);
				}
			}
			else
			{
				s=s+max(a[i],a[j]);
				if(a[i]>a[j]) a[j-1]=a[j-1]-(a[i]-a[j]);
				else a[i+1]=a[i+1]-(a[j]-a[i]);
			}
		}
		else if(b[i]!=b[j])
		{
			s+=a[i];
		}
	}
	cout<<s;
	return 0;
}
