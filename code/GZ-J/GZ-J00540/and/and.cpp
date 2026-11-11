//GZ-J00540 顾浩扬 兴义市弘毅中学 
#include<bits/stdc++.h>
using namespace std;
long long n,m,k,p,y;
int a[200005],b[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    scanf("%lld %lld",&n,&m);
    for(long long i=1;i<=n;i++)
    	cin>>a[i];
	for(long long i=1;i<=(1<<n);i++){
		k=0;
		for(long long j=0;j<n;j++){
			if(i&(1<<j)){
				k++;
				b[k]=a[j];
			}
	}
		if(k==m){
			for(long long x=2;x<=m;x++)
				b[i]&=b[i-1];
			p=b[m];
			if(p>y) y=p;	
		}
	}
	printf("%d",y);
	return 0;
} 
