#include<bits/stdc++.h>
using namespace std;
long long a[500010];
long long tong[500010],w[500010],tongans[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","r",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	} 
	for(long long i=1;i<=n;i++){
		memset(tong,0,sizeof(tong));
		memset(w,0,sizeof(w));
		for(long long j=i;j<=n;j++){
			if(tong[a[j]]!=0){
				for(long long k=w[a[j]];k<=j;k++){
					tong[a[k]]=0;
				}
			}
			tong[a[j]]++;
			w[a[j]]=j;
		}
		for(long long i=1;i<=m;i++){
			if(tong[i]!=0){
				tongans[i]++;
			}
		} 
	}
	for(long long i=1;i<=m;i++){
		if(tongans[i]!=0){
			cout<<tongans[i]<<" ";
		}
	}
	return 0;
}
