#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long int a,b,d,e,f,g;
	cin>>a>>b;
	int c[a];
	for(long long int i=1;i<a;i++){
		long long int b;
		cin>>b;
		c[a]=b;
	}
	for(long long int j=1;j<=m;j++){
		for(long long int i=0;i<a;i++){
			if(i=0){
				e=c[i];
			}else{
				if(c[i]<c[i-1]){
					e=c[i];
					g=i;
				}
			}
		}
		f=e;
		if(g==0){
			c[g]=c[g+1];
		}else{
			c[g]=c[g-1];
		}
	}
	for(int i=0;i<a;i++){
		if(i=0){
			d=c[i];
		}else{
			d=min(c[i-1],c[i]);
		}S
	}
	cout<<d;
	return 0;
}
