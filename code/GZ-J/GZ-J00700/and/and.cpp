//GZ-J00700 陈梓灿 遵义市第四初级中学 
#include<bits/stdc++.h>
using namespace std;
bool abc(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
long long n,m,b,c,d=0,e=1;
cin>>n>>m;
long long a[n+5]={0},f[n+5]={0};
for(long long i=0;i<n;i++){
	cin>>a[i];
	b=a[i];
	while(b!=0){
		c=b%2;
		d=d+c*e;
		b=b/2;
		e=e*10;
	}
	f[i]=d;
	d=0;
	e=1;
}
sort(f,f+n,abc);
int p=f[0],q=f[1],x=0,y=0,z=0,s,h=1;
if(m==1){
	while(p!=0){
	    s=p%10;
    	z=z+s*h;
		p=p/10;
		x++;
		h=h*2;
	}
	
}

cout<<z;
	return 0;
}

