#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],c[300005],d[300005],x[300005],b[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >>n>>m;
	for(long long i=1;i<=n;i++){
		cin >>a[i];
	}
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=m;j++){
			b[j]=0;
		}
		long long t=0;
		for(long long j=i;j<=n;j++){
			long long o=o=a[j];
			if(b[o]!=1){
				t++;
				b[o]=1;
				c[o]=t;
				d[o]++;
				x[t]=o;
			}
			else{
				for(long long k=c[o]+1;k<=t;k++){
					long long op=x[k];
					b[op]=0;
					d[op]--;
				}
				t=c[o];
			}
		}
//		for(long long j=1;j<=t;j++){
//			cout<<x[j]<<" ";
//		}
	}
	for(long long i=1;i<=m;i++){
		cout<<d[i]<<" ";
	}
	return 0;
} 
