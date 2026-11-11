#include<bits/stdc++.h>
using namespace std;
int a[200005];
int b[100000000];
int yy(long long x,long long y){
	int h=0;
	int ws=1;
	while(x>0&&y>0){
		if(x%2==y%2&&y%2==1){
			h+=ws;
		}
		x/=2;
		y/=2;
		ws*=2;
	}
	return h;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int f1=0,f2=0;
	long long zdd=-1; 
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(f2==0)if(a[i]!=a[i-1])f2=1;
		if(f1==0)if(yy(a[i],(1<<20)-1)!=a[i])f1=1;
		if(a[i]>zdd&&m!=n)zdd=a[i];
		if(m==n){
			if(i==1)zdd=a[i];
			else zdd=yy(zdd,a[i]);
		}
	}
	if(m==n-1){
		int ddd=-1,aaa=0;
		for(int i=1;i<=n;i++){
			aaa=0;
			for(int j=1;j<=n;j++){
				if(j==1 || i==1&&j==2){
					aaa=a[j];
				}
				else if(j!=i){
					aaa=yy(aaa,a[j]);
				}
			}
			if(aaa>ddd)ddd=aaa;
		}
		cout<<ddd;
		return 0;
	}
	if(m==n){
		cout<<zdd;
		return 0;
	}
	if(f1==0){
		sort(a+1,a+n+1);
		cout<<a[n-m+1];
		return 0;
	}
	if(m==1){
		cout<<zdd;
		return 0;
	}
	
	
	long long f=1<<n;
	long long zd=-1;
	for(int i=1;i<=f;i++){
		int w=i;
		int p=0,yyy=0;
		while(w){
			int u=w%2;
			yyy+=u;
			b[p+1]=u;
			w=w/2;
			p++;
			if(w==0)break;
		}
		if(yyy==m){
			long long k=0,ll=0;
		for(int j=1;j<=n;j++){
			if(b[j]==1){
				if(ll==0){
					ll=1;
					k=a[j];
				}
				else{
					k=yy(k,a[j]);
				}
			}
		}
		if(k>zd)zd=k;
		}
		
	}
	cout<<zd;
	return 0;
}  
