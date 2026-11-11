#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],maxx,x;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		maxx=max(a[i],maxx);
	}
	if(m==1) printf("%lld",maxx);
	else if(m==n){
		maxx=a[1];
		for(int i=2;i<=n;i++) maxx=(maxx)&(a[i]);
		printf("%lld",maxx);
	}
	else if(m==2){
		maxx=-1;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxx=max(maxx,(a[i]&a[j]));
			}
		}
		printf("%lld",maxx);
	}
	else if(m==n-1){
		x=a[1];
		for(int i=2;i<=n-1;i++) x=x&a[i];
		maxx=max(maxx,x);	
		x=a[2];
		for(int i=3;i<=n;i++) x=x&a[i];
		maxx=max(maxx,x);
		printf("%lld",maxx);
	}
	else cout<<1;
	return 0;
}
