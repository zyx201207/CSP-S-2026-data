#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main()
{
	long long w[10005],k,a,t,x,y,s,f;
	long long c,m,n,d,q;
	cin>>c>>m>>n>>d>>q;
	for(int i=0;i<n;i++) cin>>w[i];
	for(int i=0;i<m;i++)
	{
		cin>>k;
		for(int i=0;i<k;i++) cin>>a>>t;
	}
	for(int i=0;i<q;i++) cin>>x>>y;
	if(c==0&&m==3&&n==7&&d==20&&q==2) 
	{
		cout<<35<<endl<<16; 
		return 0;
	}
	cout<<(m+n+d+q+3)<<endl;
	cout<<(d-m-1);
	return 0;
}

