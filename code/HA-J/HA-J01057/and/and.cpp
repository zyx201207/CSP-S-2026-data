#include<bits/stdc++.h>
using namespace std;
string s,s1,s2,s3;char v;
long long int a[10000],b[10000],c,d,e,f=0,g,n,t,m;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int j=1;j<=n;j++)
	{
	    cin>>a[j];
		if(a[j]>t)
		t=a[j];	
	}
	cout<<t;
	return 0;
}

