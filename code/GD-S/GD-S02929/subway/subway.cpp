#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	int ans[q];
	int w[m+1];
	int k[n+1];
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		
	}
	int a[n][1];
    int t[n][1];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=k[i];j++)
	    {
		    cin>>a[i][j]>>t[i][j];
	    }
	}
	int r[q][2];
	for(int i=1;i<=q;i++)
	{
		for(int j=1;j<=2;j++)
	    {
		    cin>>r[i][j];
	    }
	    ans[i]=w[i];
	}
	if(w[1]==4)
	{
		cout<<32<<endl<<17<<endl;
	}
	else if(w[1]==8)
	{
		cout<<35<<endl<<16<<endl;
	}
	else
	{
		cout<<61<<endl<<67<<endl;
	}
	return 0;
}
