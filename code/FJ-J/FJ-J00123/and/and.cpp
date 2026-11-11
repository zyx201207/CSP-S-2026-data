#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005]={0},s,maxx=0,x=0,w;
int b[4]={0};
int sss(int z){
	if(z==m){
		if(s>maxx){
			maxx=s;
		}
		return 0;
	}
	if(x>n){
		return 0;
	}
	x++;
	sss(z);
	x--;
	w=s;
	if(z==0){
		s=a[x];
	}else{
		s=s&a[x];
	}
	z++;
	x++;
	sss(z);
	x--;
	s=w;
	return 0;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	x=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>=4){
			x=2;
		}
	} 
	if(m==1){
		sort(a+1,a+1+n);
		cout<<a[n];
		return 0;
	}
	if(m==n){
		int ss=a[1];
		for(int i=2;i<=n;i++){
			ss=ss&a[i];
		}
		cout<<ss;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				s=a[i]&a[j];
				if(s>maxx){
					maxx=s; 
				}
			}
		}
		cout<<maxx;
		return 0;
	}
	if(m==n-1){
		for(int i=1;i<=n;i++){
			s=0;
			for(int j=1;j<=n;j++){
				if(j!=i){
					if(s!=0){
						s=s&a[j];
					}else{
						s=a[j];
					}
				}
			}
			if(s>maxx){
				maxx=s;
			}
		}
		cout<<maxx;
		return 0;
	}
	if(x==0){
		for(int i=1;i<=n;i++){
			b[a[i]]++;
		}
		if(b[3]>=m){
			cout<<3;
			return 0;
		}
		if(b[3]+b[2]>=m){
			cout<<2;
			return 0;
		}
		if(b[3]+b[1]>=m){
			cout<<1;
			return 0;
		}
		cout<<0;
		return 0;
	}
	s=0;
	x=2;
	sss(0);
	s=a[1];
	sss(1);
	cout<<maxx;
	return 0;
}
