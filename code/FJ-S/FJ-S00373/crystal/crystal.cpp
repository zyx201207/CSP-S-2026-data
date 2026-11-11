#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long b[500005];
long long f(int l,int r){
	return b[r]-b[l-1];
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	int ma=0;
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		while(l<=r){
			int md=l+r>>1;
			if(a[i]*(i-md+1)-f(md,i)<=m){
				r=md-1;
			}
			else{
				l=md+1;
			}
		}
		ma=max(ma,i-l+1);
	}
	printf("%d",ma);
}
