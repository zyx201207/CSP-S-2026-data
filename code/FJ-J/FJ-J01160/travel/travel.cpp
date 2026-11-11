#include<bits/stdc++.h>
using namespace std;
struct node{
	int a;
	string s;
};
node r,x;
bool b(node x,node y){
	return x.a==y.a;
	
}
bool c(node x,node y){
	if(b(x,y)){
		int q=int(x.s[0]+x.s[1]),w=int(y.s[0]+y.s[1]);
		if(q==w){
			return true;
		}
	}
	return false;
}
bool d(node x,node y){
	if(b(x,y)&&c(x,y)){
		if((x.s[2]>='A'&&x.s[2]<='C' && y.s[2]>='A'&&y.s[2]<='C')||(x.s[2]>='D'&&x.s[2]<='F' && y.s[2]>='D'&&y.s[2]<='F'))
			return true; 
	}
	return false;
}
bool e(node x,node y){
	if(b(x,y)&&c(x,y)&&d(x,y)){
		if(int(x.s[2])+1==int(y.s[2])||int(y.s[2])+1==int(x.s[2])||x.s[2]=='D'&&y.s[2]=='F'||y.s[2]=='D'&&x.s[2]=='F'){
			return true;
		}
	}
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("trevel.out","w",stdout);
	cin>>r.a>>r.s>>x.a>>x.s;
	if(b(r,x)){
		cout<<1;
	}else{
		cout<<0;
	}
	if(c(r,x)){
		cout<<1;
	}else{
		cout<<0;
	}
	if(d(r,x)){
		cout<<1;
	}else{
		cout<<0;
	}
	if(e(r,x)){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
