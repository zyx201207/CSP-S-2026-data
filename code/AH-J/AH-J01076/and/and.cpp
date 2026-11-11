#include<bits/stdc++.h>
using namespace std;

	bool pd(int x)
	{
		if(x%2==0)
			return false;
		x/=2;
		if(x==1)
			return true;
	}

int main()
{

	freopen("and.in","r","stdin");
	freopen("and.out","w","stdout");
	//
	long long n,m,ans;
	cin>>n>>m;
	long long a[1000005];
	bool A=1;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	ans=a[1];
	if(m==n)
	{
		for(int i=2;i<=n;i++)
			ans=ans&a[i];
		cout<<ans;
		return 0;
	}
	if(m==1)
	{
		for(int i=2;i<=n;i++)
			if(a[i]>ans)
				ans=a[i];
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++)
		if(!pd(a[i]))
			A=0;
	if(A)
	{
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				if(a[i]<a[j])
					swap(a[i],a[j]);
		cout<<a[m];
		return 0;	
	}		

	return 0;
}
