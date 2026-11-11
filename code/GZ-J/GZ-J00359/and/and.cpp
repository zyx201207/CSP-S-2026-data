//GZ-J00359 观山湖区铭苑中学 常淋淇 
#include<bits/stdc++.h>
using namespace std;
int A(int a){
	int i=1,e=0;
	while(a){
		e+=a%2*i;
		i*=10;
		a/=2;
	}
	return e;
}
int B(int a){
	int s=0,n=1;
	while(a){
		s+=a%10*n;
		n*=2;
		a/=10;
	}
	return s;
}
int Y(long long a,long long b){
	int w=0,i=1;
	while(min(a,b)){
			if(a%10==b%10) w=w*10+1;
			else w=w*i;
			a/=10;b/=10;i*=10;
	} 
	w=B(w);
	return w;
}
int main(){
	freopen;{"and.in","r",stdin;}
	freopen;{"and.out","w",stdout;}
	int n,m,w=0,d=0;cin>>n>>m;
	int a[n];long long b[n];	
	for(int i=0;i<n;i++){
		cin>>a[i];b[i]=A(a[i]);
		if(m==2){
			w=Y(b[i],b[i-1]);
			d=max(w,d);
		}
	}
	if(m!=2){
		for(int i=m;i<n;i++){
			for(int j=m-1;j>=m;j--){
				w=Y(b[i],b[i-j]);
				d=max(w,d);
			}
		}
	}
	cout<<d;
	return 0;	
}
