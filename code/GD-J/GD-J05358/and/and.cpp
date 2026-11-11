#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],u[200005][35],maxx,bei,l,p;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1; i<=n; i++){
		scanf("%lld",&a[i]);
		bei=1; l=1;
		while(a[i]>0){
			if(a[i]==bei||a[i]%(bei*2)==bei){
				a[i]-=bei;
				u[i][l]=1;
			}
			bei*=2; l+=1;
		}
	}
	for(int i=1; i+m-1<=n; i++){
			p=0;
			bei=1; l=1;
			while(l<30){
				if(m%2==0&&u[i+m-1][l]-u[i-1][l]%2==0&&u[i+m-1][l]!=0)p+=bei;
				if(m%2==1&&u[i+m-1][l]-u[i-1][l]%2==1)p+=bei;
				bei*=2; l+=1;
			}
			maxx=max(maxx,p);
	}
	printf("%lld",maxx);
	return 0;
}
