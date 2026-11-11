#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500000],b[500000],bnow,now,t,c[300000];
long long f(){
	for(int i=0;i<bnow;i++){
		if(t==b[i]){
			return i;
		}
	}
	return -1;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		scanf("%lld",&a[i]);
	}
	for(int x=0;x<n;x++){
		for(int i=0;i+now<n;i++){
			t=a[i+now];
			long long t2=f();
			if(t2==-1){
				b[bnow++]=t;
			}else{
				int j=t2;
				for(int j=t2;j<bnow;j++){
					b[j]=0;
				}
				bnow=bnow-j;
				b[bnow++]=t;
			}
		}
		for(int i=0;i<bnow;i++){
			c[b[i]]++;
			b[i]=0;
		}
		now++;
		bnow=0;
	}
	for(int i=1;i<=m;i++){
		printf("%lld ",c[i]);
	}
	return 0;
}
