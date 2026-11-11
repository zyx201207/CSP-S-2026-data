#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100005],w,c[100005],l;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
			cin>>a[i];
	}
	for(long long i=1;i<=n;i++){
		long long b[100005]={};
		for(long long j=i;j<=n;j++){
			if(b[a[j]]<1)
				b[a[j]]++;
			else{
				for(long long k=j-1;;k--){
					if(a[k]==a[j]){
						break;
					}
					b[a[k]]--;	
				}
			}
		} 
		for(long long j=1;j<=n;j++){
			if(b[j]==1)
				c[j]++;
		} 
	}
	for(long long i=1;i<=m;i++){
		printf("%lld ",c[i]);
	}
	return 0;
}  
