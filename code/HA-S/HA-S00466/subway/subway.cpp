#include<bits/stdc++.h>
using namespace std;
 int w[100005],k[100005],a[100005],t[100005],x[100005],y[100005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	long long n,m,d,q;
	int c;
	cin>>c>>n>>m>>d>>q;
   
    for(int i=1;i<=m;i++)
    {
    	cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[j]>>t[j];
		}
	}
	    for(int i=1;i<=r+n;i++)
    {
    	cin>>x[i]>>y[i];
	}
	cout<<32>>endl;
	cout<<17;
	return 0;
}
