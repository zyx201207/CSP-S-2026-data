#include<bits/stdc++.h>
using namespace std;
	long long a[30005];
	long long s,x;
	string w,q;
	long long ss;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	string c;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		cin>>c[i];
		s+=a[i];
	}
	long long k=s;
	if(s%2==0){
		s=s/2;
	}
	else{
		s=s-1;
		s=s/2;
	}
	long long b=1;
	char z;
	z=c[0];
	long long t=0;
	for(int i=0;i<s;i++){
		w[i]=z;
		if(b==a[t]){
			b=0;
			t++;
			z=c[t];
		}
		b++;
	}
	b=1;
	z=c[n-1];
	t=n-1;
	if(k%2==0){	
	for(int i=0;i<k-s;i++){
		q[i]=z;
		if(b==a[t]){
			b=0;
			t--;
			z=c[t];
		}
		b++;
	}
}
	if(k%2==1){	
	for(int i=0;i<k-s-1;i++){
		q[i]=z;
		if(b==a[t]){
			b=0;
			t--;
			z=c[t];
		}
		b++;
	}
}
for(int i=0;i<s;i++){
	if(w[i]!=q[i]){
		ss++;
	}
}
cout<<ss;
	return 0;
}
