#include <bits/stdc++.h>
using namespace std;
long long a[10000000],kindm[10000000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++){
		long long table[n+1];
		long long cnt[m+1];
		for(int j=1;j<=m;j++){
			cnt[i]=0;
		}
		for(long long j=i;j<=n;j++){
			table[j]=a[j];
			cnt[table[j]]++;
			if(cnt[table[j]]>1){
				for(long long k=1;k<=n;k++){
					if(table[k]==table[j]){
						for(long long l=k;l<j-1;l++){
							cnt[table[l]]=0;
							table[l]=0;
						}
					}
				}
			}
		}
		for(long long j=1;j<=m;j++){
			if(cnt[j]>0){
				kindm[j]++;
			}
		}
	}
	for(long long i=1;i<=m;i++){
		cout<<kindm[i]<<" ";
	}
}
