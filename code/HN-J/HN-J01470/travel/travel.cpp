#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	int q=0,w=1,e=0,r=0;
	
	if(a!=c){
		q=0;
		cout<<q;
	}else{
		q=1;
		cout<<q;
	}
	
	
	
	w=1;
	if(q==1){
	for(int i=0;i<2;i++){
		if(b[i]!=d[i]){
			w=0;
		}
	}
	cout<<w;
	}else{
		cout<<0;
	}
	
	
	
	if(w==1){
		if(b[2]>='A'&&b[2]<='C'&&d[2]>='A'&&d[2]<='C'){
			e=1;
			cout<<e;
		}else if(b[2]>='D'&&b[2]<='F'&&d[2]>='D'&&d[2]<='F'){
			e=1;
			cout<<e;
		}else{
			e=0;
			cout<<e;
		}
	}else{
		cout<<0;
	}
	
	
	if(e==1){
		if(char(b[2]+1)==d[2]){
			r=1;
			cout<<r;
		}else if(char(b[2]-1)==d[2]){
			r=1;
			cout<<r;
		}else{
			r=0;
			cout<<r;
		}
	}else{
		cout<<0;
	}
	return 0;
}
