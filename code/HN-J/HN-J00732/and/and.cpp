#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[200010],m1=LLONG_MIN;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==1){
		for(int i=1;i<=n;i++){
			ll a1=a[i],b=0,k=1;
			while(a1>0){
				b+=a1%2*k;
				a1/=2;
				k*=10;
			}
			ll r=0,d=1;
			int e=b;
			while(e>0){
				r+=e%10*d;
				d*=2;
				e/=10;
			}
			m1=max(m1,r);
		}
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			ll o=a[i],x=0,u=1;
			while(o>0){
				x+=o%2*u;
				o/=2;
				u*=10;
			}
			for(int j=i+1;j<=n;j++){
				ll a1=a[j],b=0,k=1;
				while(a1>0){
					b+=a1%2*k;
					a1/=2;
					k*=10;
				}
				ll y=x&&b;
				x=max(x,y);
				ll q=0;
				ll z=1;
				int g=x;
				while(g>0){
					q+=g%10*z;
					z*=2;
					g/=10;
				}
				m1=max(m1,q);
			}
		}
	}
	cout<<m1;
	return 0;
}
