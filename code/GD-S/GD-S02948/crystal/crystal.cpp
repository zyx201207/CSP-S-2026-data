#include<bits/stdc++.h>
using namespace std;
main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long a,b,c,d,e[500000]={},g,h,o;
	cin>>a>>b;
	c=0;
	d=0;
	for(int i=0;i<a;i++){
		cin>>e[i];
		c=max(c,e[i]);
		if(d>e[i]){
			d=e[i];
		}
	}
	h=0;
	for(int i=d;i<=c;i++){
		o=0;
		long long f[500000]={};
		for(int j=0;j<a;j++){
			if(i>e[j]){
				f[j]=i-e[j];
			}else{
				f[i]=e[j]-i;
			}
		}
		for(int j=0;j<a;j++){
			for(int k=j;k<a;k++){
				if(f[j]>f[k]){
					g=f[j];
					f[j]=f[k];
					f[k]=g;	
				}
			}
		}
		g=0;
		for(int j=0;j<a;j++){
			if(g+f[j]>b){
				break;
			}else{
				g=g+f[j];
				o++;
			}
		}
		h=max(h,o);
	}
	cout<<h-1;
	return 0;
} 
