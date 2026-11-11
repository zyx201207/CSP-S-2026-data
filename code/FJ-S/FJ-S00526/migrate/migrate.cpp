#include<bits/stdc++.h>
using namespace std;
const long long N=2e6+2;
long long c,t,n,a[N],b[N];
long long d,x[N],s;
int main(){
	freopen("migrate.in" ,"r",stdin );
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		long long v=0,t=0;
		s=0;
		cin>>n>>d;
		for(long long i=1;i<=n;i++)
			cin>>x[i];
		x[0]=-3e18-1;
		x[n+1]=3e18+1;
		for(long long i=1;i<n;i++)
			if(x[i]+d<x[i+1])
				b[++t]=i;
		b[0]=0;
		b[++t]=n;
		for(long long i=1;i<=n-3;i++)
			if(x[i]+d>=x[i+2]&&x[i+1]+d>=x[i+3]&&x[i]+d<x[i+3])
				a[++v]=i;
		a[0]=0;
		a[v+1]=n-2;
		long long u=0;
		for(long long i=1;i<=v;i++){
			while(b[u]<a[i]&&u<=t)
				u++;
			
			long long l=min(a[i]-a[i-1],a[i]-b[u-1]),r=min(a[i+1]-a[i],b[u]-a[i]-2);
			if(x[a[i]-1]+d>=x[a[i]+1])
				l=1;
			if(x[a[i]+2]+d>=x[a[i]+4])
				r=1;
			s+=l*r;
		}
		cout<<s<<"\n";
	}
	return 0;
}
