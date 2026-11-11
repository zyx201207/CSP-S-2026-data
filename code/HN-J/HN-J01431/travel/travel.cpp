#include<bits/stdc++.h>
using namespace std;
string a,b,x,y;
bool one(){
	for(int i=0;i<2;i++){
		if(b[i]!=y[i]) return false;
	}
	return true;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>x>>y;
	cout<<(a==x);
	if(a!=x){
		cout<<"000";
		return 0;
	}
	cout<<one();
	if(!one()){
		cout<<"00";
		return 0;
	}
	char s=b[2],t=y[2];
	if((s<='C'&&t<='C')||(s>='D'&&t>='D')){
		cout<<1;
		if(s>='D'&&t>='D'&&abs(s-t)==2){
			cout<<1;
		}
		else if(s<='C'&&t<='C'&&abs(s-t)==1){
			cout<<1;
		}
		else cout<<0;
	}
	else{
		cout<<"00";
	}
	return 0;
}

