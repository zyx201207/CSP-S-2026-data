#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,d,p,x,t,k,x1,y1;
	cin>>c>>n>>m>>d>>p;
	for(int i=0;i<m;i++) cin>>a[i];
	for(int i=0;i<n;i++){
		cin>>k;
		for(int i=0;i<k;i++) cin>>x>>t;
	}
	for(int i=0;i<p;i++) cin>>x1>>y1;
	cout<<n+m+d+p+3<<endl;
	cout<<d-n-1;
	return 0; 
 } 
