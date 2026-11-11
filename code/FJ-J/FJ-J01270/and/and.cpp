#include<bits/stdc++.h>
using namespace std;
const int M=200005;
int a[M];int b[M][31];bool ys[M];
int h[31];int j=0;
int u[31];int n;
void Isq(int d,int w){
	int wei=1;
	while(d){
		int l;
		if(a[w]%2==0){
		  l=0;
		}else{
		  l=1;
		}
		b[w][wei]=l;
		h[wei]+=b[w][wei];
		wei++;
		d/=2;
	}
	j=max(j,wei-1);
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	int m;cin>>n>>m;
	
	int p;int o=0;
	bool ok=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		Isq(a[i],i);
		if(a[i]>4) ok=0;
		if(n<=2000){
			o=max(o,a[i]);
			if(i==1) p=a[i];
			else p=p&a[i];
		}
	}
	if(m==n){
		cout<<p;
		return 0;
	}else if(m==1){
		cout<<o;
		return 0;
	}
	
	if(n<=2000){
		if(m==2){
			int o=0;
			for(int i=1;i<=n;i++){
				for(int j=1;j<i;j++){
					int p=a[i]&a[j];
					o=max(o,p);
				}
			}
			cout<<o;
			return 0;
		}
	}
	if(ok){
		int a1=0,a2=0,a3=0,a4=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1) a1++;
			if(a[i]==2) a2++;
			if(a[i]==3) a3++;
			if(a[i]==4) a4++;
		}
		if(a4>=m){
			cout<<4;
		}else if(a3>=m){
			cout<<3;
		}else if(a3+a2>=m){
			cout<<2;
		}else if(a1+a3>=m){
			cout<<1;
		}else{
			cout<<0;
		}
		return 0;
	}
	sort(a,a+n+1);
	cout<<a[n-m+1];
	return 0;
	for(int i=j;i>=1;i--){
		if(h[i]>=m){
			u[i]=1;
			for(int x=1;x<=i;x++){
				h[x]=0;
			}
			for(int x=1;x<=n;x++){
				if(b[x][i]==0) ys[x]=1;
				if(!ys[i]) Isq(a[x],x);
			}
		}
	}
	cout<<h[1];
	int er=2;
	int k=u[1];
	for(int i=2;i<=30;i++){
		k+=er*u[i];
		er*=2;
	}
	cout<<k;
}
