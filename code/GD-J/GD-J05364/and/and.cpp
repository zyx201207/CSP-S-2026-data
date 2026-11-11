#include<iostream>
#include<cstdio>
using namespace std;
int a[200005],b[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long ans=0;
	long long m,n,bmin=1;
	int k,q;
	scanf("%lld %lld",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			k=a[i]&a[j];
			for(q=0;q<m;q++){
				if(b[q]<bmin) bmin=b[q];
			}
			if(bmin<k){
				b[q-1]=k;
			}
		}
	}
	for(int i=0;i<m;i++){
		ans=ans+b[i];
	}
	printf("%lld",ans);
	return 0;
}
