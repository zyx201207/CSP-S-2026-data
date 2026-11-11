#include<bits/stdc++.h>
using namespace std;
long long b,d=0,e=0,h=0;
char g,c[1000000],f[10000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int a;
	cin>>a;
	for(int i=0;i<a;i++){
		cin>>b>>g;
		f[i]=g;
		for(long long j=d;j<d+b;j++){
			c[j]=g;
		}
		d+=b;
	}
	for(int i=0;i<a;i++){
		if(f[i]==f[i+1]){
			h++;
		}
	}
	if(h=a-1){
		e--;
	}
	for(long long i=0;i<a;i++){
		if(c[i]!=c[d-i]){
			c[d-i]=c[i];
			e++;
		}
	}
	cout<<e;
	return 0;
}
