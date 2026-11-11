#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	int a,s,d,f,g,h,j,k,l;
	string z,x,c,v,b,n;
	cin>>z>>x>>c>>v;
	if(z==c){
		cout<<1;
		b=x[0]+x[1];
		n=v[0]+v[1];
		if(b==n){
			cout<<1;
			if(x[2]>='A'&&x[2]<='C'){
				s=1;
			}else if(x[2]>='D'&&x[2]<='E'){
				s=2;
			}
			if(v[2]>='A'&&v[2]<='C'){
				d=1;
			}else if(v[2]>='D'&&v[2]<='E'){
				d=2;
			}
			if(s==d){
				cout<<1;
				h=abs(x[2]-v[2]);
				if(h==1){
					cout<<1;
				}else{
					cout<<"0";
				}
			}else{
				cout<<"00";
				return 0;
			}
		}else{
		cout<<"000";
		return 0;
		}
	}else{
		cout<<"0000";
		return 0; 
	}
	return 0;
}
