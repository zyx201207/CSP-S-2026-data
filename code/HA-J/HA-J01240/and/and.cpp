#include<bits/stdc++.h>
using namespace std;
long long b[200007][31];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m,n,ma=32;
	cin>>n>>m;
	long long a[n+1],cnt=0,sum=0,w=0;
	for(int i=0;i<n;i++){
		cnt=0;
		cin>>a[i];
		while(a[i]>=1){
			b[i][cnt]=a[i]%2;
			a[i]/=2;
			cnt++;
		}
	}
	cnt=0;
	while(ma>=1){
		for(int i=0;i<ma;i++){
			sum=0;
			for(int j=0;j<n;j++){
				if(b[j][i]==1){
					sum++;
				}
			}
			if(sum>=m){
				w=i;
			}
		}
		ma=w;
		long long qq;
		if(ma==0){
			qq=0;
		}
		else{
			qq=1;
		}
//		for(int k=0;k<n;k++){
//			if(b[k][ma]!=1){
//				for(int e=ma;e>=0;e--){
//					b[k][e]=0;
//				}
//			}
//		}
		for(int i=1;i<=ma;i++){
			qq*=2;
		}
		cnt+=qq;
	}
	cout<<cnt;
	return 0;
}
