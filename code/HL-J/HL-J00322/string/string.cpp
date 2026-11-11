#include<bits/stdc++.h>
using namespace std;
int snm;
int main()
{
	int n;
	cin>>n;
	int a[n];
	int s;
	for(int i=1;i<=n;i++)
	{
	    cin>>a[i];
	    snm+=a[i];
	    char w;
	    cin>>w;
	}
	int pig=1,vb=n;
	cout<<snm;
	return 0;
}
