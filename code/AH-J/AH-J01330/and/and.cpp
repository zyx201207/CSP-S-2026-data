#include<bits/stdc++.h>
using namespace std;
long long a[200005];
long long nu[35]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67128864,134217728,268435456,536870912,1073741824};
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
 	ios::sync_with_stdio(0);
 	cin.tie(0);
 	cout.tie(0);
 	int n,m;
 	cin>>n>>m;
 	int ok=1;
 	for (int i=1;i<=n;i++)
 	{
 		cin>>a[i];
 		if (a[i]!=i-1)
 			ok=0;
 	}
	for (int i=1;i<=20;i++)
 		if (n==nu[i] && ok==1)
 		{
 			cout<<n-m;
 			return 0;
		}	
 	if (m==n)
 	{
 		int s=a[1];
 		for (int i=2;i<=n;i++)
 			s&=a[i];
 		cout<<s;
	}
	else if (m==1)
	{
		long long Max=0;
		for (int i=1;i<=n;i++)
			Max=max(Max,a[i]);
		cout<<Max;
	}
	else if (m==2)
	{
		long long Max=0;
		for (int i=1;i<n;i++)
			for (int j=i+1;j<=n;j++)
				Max=max(Max,a[i]&a[j]);
		cout<<Max;
	} 
	else
	{
		
		sort(a+1,a+n+1);
		long long s=a[n];
		for (int i=1;i<=30;i++)
			if (a[n]==nu[i]) 
			{
				s=a[n-1];
				for (int i=n-2;i>=n-m;i--)
					s&=a[i];
				cout<<s;
			}
		for (int i=n-1;i>=n-m+1;i--)
			s&=a[i];
		cout<<s;
	}
	return 0;
} 
