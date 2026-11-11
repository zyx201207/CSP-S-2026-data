#include<bits/stdc++.h>
using namespace std;
struct zkc{
	long long ans ,t;
}c[500005];
long long  ccc,n,m,d,q,a[500005],b[500005],k,t,ans,s,e,z;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>ccc >>n>>m>>d>>q;
	for(long long i=1;i<=m;i++){
		cin>>a[i];
	} for(long long j=1;j<=n;j++){
		cin>>k;
		for(long long l=1;l<=k;l++){
			cin>>c[l].ans>>c[l].t;
		}
	}
	for(long long h=1;h<=q;h++){	
		cin>>s>>e;
		for(long long i=1;i<=m;i++){
			for(long long j=1;j<=n;j++){
				for(long long l=1;l<=k;l++){
					z+=a[s];
					if(s==c[l].ans){
						z+=c[l].t ;
						s=c[l].ans+1;
					}if(s==e){
						z+=a[e];
						cout<<z<<endl;
						z=0;
					}
				}
			}
		}
	}
}

