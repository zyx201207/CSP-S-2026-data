#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long a,c[200100],d=0,f[200100];
	string s,b;
	long long j=0,k=0,x=0,y=0,h=0;
	cin>>a;
	for(int i=1;i<=a;i++){
		cin>>c[i]>>s[i];
		d+=c[i];
	}
	for(int i=1;i<=d/2;i++){
		f[d-i+1]=c[i];
		b[d-i+1]=s[i];}
	for(int i=1;i<=d/2;i+=min(c[k],f[y])){
		while(j<i){j+=c[k];
			k++;}
		while(x<i){x+=f[y];
			y++;}
		if(s[k]!=b[y]) h+=min(c[k],f[y]);
	}
	cout<<h;
} 
		
		
		
