#include<bits/stdc++.h>
using namespace std;
long long t[200005],t2[200005],sum[200005],f[200005],ans;
char a[200005];
long long n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>t[i]>>a[i];
		sum[i]=sum[i-1]+t[i];
	}
	long long l=0,lc=1,rc=n;
	while(lc!=rc&&l<=(sum[n]/2))
	{
		l=sum[lc];
		while(t[lc]!=0&&lc!=rc)
		{
			if(lc==rc) break;
			if(t[lc]>t[rc])
			{
				if(a[lc]!=a[rc]) ans+=t[rc];
				t[lc]-=t[rc];
				t[rc]=0;
				rc--;
			}
			else
			{	
				if(a[lc]!=a[rc]) ans+=t[lc];
				t[rc]-=t[lc];
				t[lc]=0;
				if(t[rc]==0) rc--;
				break;
			}
			
		}
		lc++;
	}
	cout<<ans;
	return 0;
}
