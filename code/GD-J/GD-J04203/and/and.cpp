#include<bits/stdc++.h>
using namespace std;
int n,m,t,w,ans,a[200005],q[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=30;i>=0;i--)
	{
		t=0,w=pow(2,i);
		for(int j=1;j<=n;j++) if((a[j]&w)==w) t++,q[t]=a[j];
		if(t>=m)
		{
			ans+=w;
			for(int j=1;j<=t;j++) a[j]=q[j],n=t;
		}
	}
	cout<<ans;
}
