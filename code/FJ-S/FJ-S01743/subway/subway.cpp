#include<bits/stdc++.h>
using namespace std;
long long c,n,m,de,q;
struct zhan{
	long long w;
	long long t;
}z[500005];
int main(){
    freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>de>>q;
	for(long long i=0;i<m;i++){
		cin>>z[i+1].w;
	} 
	for(long long i=0;i<n;i++){
		long long k;
		cin>>k;
		for(long long j=0;j<k;j++){
			long long a,tm;
			cin>>a>>tm;
			z[a].t=tm;
		}
	}
	for(long long i=0;i<q;i++){
		long long s,e,ans=0;
		cin>>s>>e;
		ans+=z[s].w+z[s].t+z[e].t+z[e].w;
		cout<<ans<<endl;
	}
}
