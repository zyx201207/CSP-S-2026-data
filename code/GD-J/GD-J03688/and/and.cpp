#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
int n,m,ppp=0,p=0,l=0,jjj;
cin>>n>>m;
long long a[n+1];
for(int i=1;i<=n;i++){
	cin>>a[i];l=max(a[i],l);
}
if(m==1){
cout<<l;
return 0;
}
x=a[1];
if(m==n){
	for(int i=2;i<=n;i++){
		jjj=1;
		int x=x^a[i];
		int y=x;
		while(y){
		y/=2;
		ppp++;
	}
	while(jjj<x)
	jjj*=2;
	x=jjj-ppp;
}
cout<<x;
return 0;
}
for(int j=1;j<=n;j++){
	ppp=0;
	for(int i=j+1;i<=n;i++){
		jjj=1;
		int x=a[j]^a[i];
		int y=x;
		while(y){
		y/=2;
		ppp++;
	}
	while(jjj<x)
	jjj*=2;
	x=jjj-ppp;
	p=max(p,x);
}
}
cout<<p;
return 0;
}
