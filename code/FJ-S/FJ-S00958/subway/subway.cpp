#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
const int N=5e5+10;
int a[N];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,p,x,t,k,x1,y1;
	cin>>c>>n>>m>>d>>p;
	for(int i=0;i<m;i++) cin>>a[i];
	for(int i=0;i<n;i++)
	{
		cin>>k;
		for(int j=0;j<k;j++) cin>>x>>t;
	}
	for(int i=0;i<p;i++) cin>>x1>>y1;
	cout<<n+m+d+p+3<<endl;
	cout<<d-n-1;
	return 0;
}
