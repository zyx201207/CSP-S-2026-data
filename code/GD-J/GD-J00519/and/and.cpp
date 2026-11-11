#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	long long a[200100];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	int sum=a[n-1];
	for(int i=n-1;i>=m-n;i--)
	{
		sum&=a[i];
	}
	cout<<sum;
	return 0;
}
