#include<bits/stdc++.h>
using namespace std;
long long n,a[1000000],mint=9999,ct,cu[1000000],m,c[1000000],b[1000000],maxn;
void z(){
	long long cf=1,sum=0;
	for(int i=1;i<mint;i++){
		sum+=c[i]*cf;
		cf*=2;
	}
	mint=99999;
	for(int i=0;i<1000000;i++){
		cu[i]=0;
	}
	ct=1;
	maxn=max(maxn,sum);
}
void an(){
	for(int i=1;i<=m;i++){
		while(b[i]){
			c[ct]=b[i]%2;
			b[i]/=2;
			if(!c[ct]){
				cu[ct]=1;
			}
			if(cu[ct]){
				c[ct]=0;
			}
			ct++;
		}
		mint=min(mint,ct);
	}
	z();
}
void f(int t,int u){
	for(int i=1;i<=n;i++){
		if(i>u){
			b[t]=a[i];
			if(t==m){
				an();
			}else{
				f(t+1,i);
			}
		} 
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	f(1,0);
	cout<<maxn;
	return 0;
}
