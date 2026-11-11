#include<bits/stdc++.h>
using namespace std;
long long p[1000000],a[1000000];
long long n,m,ans[1000000];
bool finds(long long a[],long long b,long long n){
	for(long long r=0;r<n;r++){
		if(a[r]==b) return r;
	}

	return -1;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
	cin>>n>>m;
	for(long long i=0;i<n;i++) cin>>a[i];

	for(long long i=0;i<n;i++){
		long long k=0;
		for(long long o=0;o<n;o++){
			p[o]=0;
		}
		for(long long j=i;j<n;j++){
			if(finds(p,a[j],k)!=-1){
				long long u=0;
				for(long long v=finds(p,a[j],k);v<k;v++,u++){
					p[v]=0;
				}
				k=k-u;
			}
			p[k]=a[j];
			k++;
		}
		for(long long j=0;j<k;j++)
		ans[p[j]]++;
	}

	for(long long i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
