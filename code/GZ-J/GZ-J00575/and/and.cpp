//GZ-J00575 ´úÒã³Ð 
#include<bits/stdc++.h>
using namespace std;
const int maxn=1000005;
long long a[maxn],n,m,b[maxn][31],hi=-1,c[maxn],hh=1,nnmm,n1=-1;
long long pown(long long x){
	long long nu=1;
	for(long long i=1;i<=x;i++){
		nu=nu+nu;
	}
	return nu;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	for(long long i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]!=a[i-1]){
			hh=0;
		}
		long long ck=a[i],j=1;
		while(ck){
			b[i][j]=ck%2;
			ck/=2;
			j++;
		}
		hi=max(hi,j);
		n1=max(n1,a[i]);	
	}
	if(m==1){
		cout<<n1;
		return 0;
	}
	if(hh==1){
		cout<<a[1];
		return 0;
	}
	if(n==m){
		nnmm=a[1];
		for(long long i=2;i<=n;i++){
			nnmm=nnmm&a[i];
		}
		cout<<nnmm;
		return 0;
	}
	hi-=1;
	if(m==2){
		long long ans1=-1;
		for(long long i=1;i<=n;i++){
			for(long long j=i;j<=n;j++){
				if(j!=i){
					long long na=a[i]&a[j];
					ans1=max(ans1,na);
				}
			}
		}
	cout<<ans1;
	return 0;
	}
		long long bz=m,num=0;
		for(int i=hi;i>=1;i--){
			for(long long j=1;j<=n;j++){
				if(b[i][j]!=0){
					c[j]++;
				}
			}
		}
		for(long long i=hi;i>=1;i--){
			if(c[i]>=m){
				num=num+pown(i-1);
				bz--;
			}
			if(bz<=0){
				cout<<num;
				return 0;
			}	
		}
		cout<<num;	
	return 0;
}
