#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],ans=0,sum=1;
void check(int z){
	int z1=a[z],z2=a[z-1];
	while(m>=abs(z1-z2)&&z!=1){
		z2=a[z-1];
//		cout<<"1 "<<abs(z1-z2)<<' '<<z1<<' '<<z2<<' '<<m<<endl;
		if(m>=abs(z1-z2)){
			sum++;
			m=m-abs(z1-z2);
		}else{
			break;
		}
		z--;
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans+=a[i];
	}
	sort(a+1,a+n+1);
	ans/=n;
	int l=1,r=n,z=0,b=10000000;
	while(1){
		if(l==r) break;
		int mix=(l+r)/2;
		if(a[mix]==ans){
			z=mix;
			break;
		}else if(a[mix]>ans){
			z=mix;
			r=mix;
		}else{
			l=mix+1;
		}
	}
//	cout<<z<<' '<<a[z]<<' '<<sum<<endl; 
	check(z);
	int z3=z+1;
	while(1){
		int c=(a[z3]-a[z])*sum;
//		cout<<c<<' '<<sum<<' '<<z3<<' '<<m<<endl;
		if(c>m||z3>n){
			break;
		}
		sum++;
		z3++;
		m-=c;
	}
	cout<<sum;
	return 0;
}
//5 8
//-3 -1 2 2 7
