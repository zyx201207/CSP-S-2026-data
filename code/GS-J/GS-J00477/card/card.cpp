#include<bits/stdc++.h>
using namespace std;
long long a[10001],b[10001],cnt[10001];
long long in(long long k,long long n){
	for(long long i=0;i<=n;i++){
		if(b[i]==k){
			return i;
		}
	}
	return -1;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m,len=0;
	cin >>n>>m;
	for(long long i=1;i<=n;i++){
		cin >>a[i];
	}
	for(long long i=1;i<=n;i++){
		for(long long j=i;j<=n;j++){
			if(in(a[j],len)==-1){
				b[len+1]=a[j];
				len++;
			}else{
				for(long long l=in(a[j],len);l<=len;l++){
					b[l]=0;
					len-=1;
				}
				b[len+1]=a[j];
				len++;
			}	
			for(long long j=1;j<=len;j++){
				cnt[b[j]]++;
			}
			for(long long j=1;j<=len;j++){
				b[j]=0;
			}
		}
	}
	for(long long i=1;i<=m;i++){
		if(cnt[i]){
			cout <<cnt[i]<<" ";
		} 
	}
	return 0;
}
