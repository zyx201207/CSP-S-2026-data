#include<bits/stdc++.h>
using namespace std;
long long n,m,a[300005],b[500005],c[300005],d[300005],w=0,bj;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		d[a[i]]=1;
	}
	for(long long i=1;i<=n;i++){
		w=0;
		for(long long j=i;j<=n;j++){
			bj=0;
			for(long long k=1;k<=w;k++){
				if(b[k]==a[j]){
					w=k;
					bj=1;
					break;
				}
			}
			if(bj==0){
				w++;
				b[w]=a[j];
			}
		}
		for(long long j=1;j<=w;j++){
			c[b[j]]++;
		}
	}
	for(long long i=1;i<=m;i++){
		if(d[a[i]]==1){
			cout<<c[i]<<" ";
		}
	}
	return 0;
}
