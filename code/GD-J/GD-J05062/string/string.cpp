#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,num,all=0;
	cin>>n;
	char b,a[100000005];
	for(int i=1;i<=n;i++){
		cin>>num>>b;
		for(int j=1;j<=num;j++){
			a[j]=b;
		}
	}
	
	for(int i=1;i<=n;i++){
		if(a[i]>a[n]/2&&a[i]!=a[n/2]-a[i/2]+1)
		{
			a[i]=a[n/2]-a[i/2]+1;
			all+=1;
		}
		
		
		
	}
	
	cout<<all;
	return 0;
}
