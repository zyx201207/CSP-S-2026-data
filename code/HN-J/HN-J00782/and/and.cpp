#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005];
bool b[200005];
long long bnm(long long v,long long s){
	long long h=1,p=1,l=0;
	bool u[35],c[35];
	while(v>0){
		u[h++]=v%2;
		v=v/2;
	}
	while(s>0){
		c[p++]=s%2;
		s=s/2;
	}
	for(int i=1;i<=max(h,p);i++){
		if(c[i]==1&&u[i]==1){
			long long x=1;
			for(int j=1;j<i;j++){
				x*=2;
			}
			l+=x;
		}
	}
	return l;
}
long long qer(long long t,long long r){
	if(t==0){
		return r;
	}
	long long u=-1;
	for(int i=1;i<=n;i++){
		if(b[i]==0){
			b[i]=1;
			if(r=-1){
				r=a[i];
				u=max(u,qer(t-1,bnm(r,a[i])));
				r=-1;
			}else{
				u=max(u,qer(t-1,bnm(r,a[i])));
			}
			b[i]=0;
			
		}
	}
	return u;
} 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<qer(m,-1);
	return 0;
}
