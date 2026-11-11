#include<bits/stdc++.h>
using namespace std;
long long n,m,k,l;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	if(m==0) cout<<'1';
	long long a[n],b[n-1],c[n-1],d[n-1],e[n-1];
	for(long long i=0;i<n;i++) cin>>a[i];
	for(long long i=0;i<n;i++){
		k=i;
		for(long long j=i+1;j<n;j++) if(a[j]<a[k]) k=j;
		if(k!=i){
			l=a[i];
		    a[i]=a[k];
		    a[k]=a[i];
		}
	}
	for(long long i=0;i<n-1;i++){
		b[i]=a[i+1]-a[i];
		c[i]=i+1;
		d[i]=i;
	}
	for(long long i=0;i<n;i++){
		k=i;
		for(long long j=i+1;j<n;j++) if(b[j]<b[k]) k=j;
		if(k!=i){
			l=b[i];
		    b[i]=b[k];
		    b[k]=b[i];
		    l=c[i];
		    c[i]=c[k];
		    c[k]=c[i];
		    l=b[i];
		    d[i]=d[k];
		    d[k]=d[i];
		}
    }
 for (long long i=0;i<n-1;i++){
 	long long x=i,g=0,s=b[i],p=b[i],z=0;   
 	for(long long j=0;j<n-1;j++){
 		for(long long o=0;o<n-1;o++) if(c[o]==a[x]) g=o;
 		p+=b[g];
 		s+=p;
 		z++;
 		if(m<s){
 			e[i]=z;
 			j=n;
			}
		}
	}
	long long r=0;
	for(long long i=1;i<n-1;i++){
		if(e[i]>e[r]) r=i;
	}
	cout<<e[r]+1;
	return 0;
}
