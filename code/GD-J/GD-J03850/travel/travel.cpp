#include<iostream>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string x,x1,y,y1;
	cin>>x>>x1>>y>>y1;
	if(x==y){
		cout<<1;
	}else{
		cout<<0;
	}
	string k={x1[0],x1[1]},k1={y1[0],y1[1]};
	if(k==k1&&x==y){
		cout<<1;
	}else{
		cout<<0;
	}
	if(k==k1&&x==y&&x1[2]>='A'&&x1[2]<='C'&&y1[2]>='A'&&y1[2]<='C'||k==k1&&x==y&&x1[2]>='D'&&x1[2]<='E'&&y1[2]>='D'&&y1[2]<='E'){
		cout<<1;
	}else{
		cout<<0;
	}
	if(k==k1&&x==y&&x1[2]>='A'&&x1[2]<='C'&&y1[2]>='A'&&y1[2]<='C'||k==k1&&x==y&&x1[2]>='D'&&x1[2]<='E'&&y1[2]>='D'&&y1[2]<='E'){
		if(x1[2]=='C'&&y1[2]=='D'||x1[2]=='D'&&y1[2]=='C'){
			cout<<0;
		}else if(x1[2]==y1[2]-1||x1[2]==y1[2]+1){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		cout<<0;
	}
}
