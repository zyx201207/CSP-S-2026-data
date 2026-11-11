#include<bits/stdc++.h>
using namespace std;
int n,m,a[10000005];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int maain=-1;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(maain<a[i]&a[j]) maain=a[i]&a[j];
		}
	}
	return 0;
}
