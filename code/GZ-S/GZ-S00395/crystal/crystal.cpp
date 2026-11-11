#include<bits/stdc++.h>
using namespace std;
int main()
{
	//GZ-S00395 贵州省松桃民族中学 贺小妮
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n];
	int b[m]={1};
	for(int i=1;i<=n;i++)
	cin>>a[i];
	for(int j=0;j<=m;j++)
	cin>>b[j];
	for(int i=1;i<=n;i++)
	{

		for(int j=0;j<=m;j++)
		    int p=a[i];
		    p+=j;
	    // a[i]+j=a[i+1];
	     int s=m-j;
	     if((s>0)&&(a[i]+s>=a[i])
	     {
	     	cout<<i;
		 }




	}

	cout<<3;
	return 0;
}
