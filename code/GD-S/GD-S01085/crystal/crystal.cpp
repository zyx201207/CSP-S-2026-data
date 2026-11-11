#include<bits/stdc++.h>
using namespace std;
#define N 500500
long long a[N];
long long w[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long ma=0,mi=99999999;
	for(int i=1;i<=n;i++)
	  {
	  	cin>>a[i];
	  	ma=max(ma,a[i]);
	  	mi=min(mi,a[i]);
	  }
	sort(a+1,a+n+1);
	int ans=0,x=0;
	int f1=1;
	int ss=0;
	for(int f2=1;f2<=n;f2++)
	  {
	    ss=ss+(f2-1-f1+1)*(a[f2]-a[f2-1]);
	    //cout<<ss<<endl;
	  	while(a[f2+1]==a[f2])
	  	  f2++;
	  	while(ss>m)
	  	  {
	  	  	ss=ss-(a[f2]-a[f1]);
	  	  	f1++;
		  }
		ans=max(ans,f2-f1+1);
		//cout<<f1<<" "<<f2<<" "<<ss<<" "<<ans<<endl;
	  }
	cout<<ans<<endl;
	return 0;
}
