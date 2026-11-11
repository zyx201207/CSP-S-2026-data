#include<bits/stdc++.h>
using namespace std;
main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string b,c;
	long long a,m,d,e;
	cin>>a;
	c="";
	d=0;
	e=0;
	for(int i=0;i<a;i++){
		cin>>m>>b;
		d=d+m;
		for(int i=0;i<m;i++){
			c=c+b;
		}
	}
	if(d%2==0){
		for(int i=0;i<d/2;i++){
			if(c[i]!=c[d-i-1]){
				e++;
			}
    	}
	}else{
		for(int i=0;i<(d-1)/2;i++){
			if(c[i]!=c[d-i-1]){
				e++;
			}
    	}
	}
	cout<<e;
	return 0;
}
