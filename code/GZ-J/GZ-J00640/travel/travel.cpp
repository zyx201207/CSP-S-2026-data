//GZ-J00640 遵义市第四初级中学 马骎骎 
#include<bits/stdc++.h>
using namespace std;
struct people{
	int a;
	string b;
};
int main(){
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	people x,r;
	cin>>x.a>>x.b>>r.a>>r.b;
	bool t=0,t2=0;
	if(x.a==r.a){
		t2=1;
		cout<<1;
	} else{
		cout<<0;
	}  
	if(t2==1&&x.b[0]==r.b[0]&&x.b[1]==r.b[1]){
		t=1;
		cout<<1;
	}else{
		cout<<0;
	}
	bool t1=0;
	if(t==1&&x.b[2]<='C'&&r.b[2]<='C'){
		cout<<1;
		t1=1;
	}else if(t==1&&x.b[2]>='D'&&r.b[2]>='D'){
		cout<<1;
		t1=1;
	}else{
		cout<<0;
	}
	if(t1==1&&r.b[2]+1==x.b[2]){
		cout<<1;
	}else if(t1==1&&x.b[2]+1==r.b[2]){
		cout<<1;
	}else{
		cout<<0;
	}
	
	return 0;
}
