#include<bits/stdc++.h>
using namespace std;
int a[200003];
int n,m;
long long er2(long long f){
	long long k=0;
	long long k1=1;
	while(f>0){
		k+=f%10*k1;
		f/=10;
		k1*=2;
	}
}
long long er(long long y){
	long long e=1;
	while(y>0){
		e=e*10+y%2;
		y/=2;
	}
	return e;
}
long long pd(){
	long long h=1,g=0;
	for(int L=1;L<n;L++){
		for(int R=L+1;R<=n;R++){
			long long q=er(a[L]);
			long long w=er(a[R]);
			if(q>w){
				while(w>0){
					g=g*h+((q%10)==1?(w%10==1?1:0):0);
					h*=10;
					q/=10;w/=10;
				}
				q=q*h+g;
				q=er2(q);
				return q;
			}
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);

	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(m==1){
		long long x=a[1];
		for(int i=2;i<=n;i++){
			if(a[i]>x){
				x=a[i];
			}
		}
		cout<<x;
	}else if(m==2){
		cout<<pd();
	}
	return 0;
}
