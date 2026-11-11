#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,a[200005];
	int sum=1,s=0,max=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<n;i++)
	{
		while(s==m)
		{
			sum=sum&&a[i+s];
			s++;
		}
		if(max<(a[i]&&a[i+1])) max=(a[i]&&a[i+1]);
	}
	cout<<max;
	
	return 0;
}
