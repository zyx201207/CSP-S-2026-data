#include<bits/stdc++.h>
using namespace std;
struct node {
	string id;
	string seat;
};
struct node1{
	string id1;
	string seat1;
};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,c,b,d;
	cin>>a>>b>>c>>d;
	node(n);
	node1(m);
	n.id=a;
	n.seat=b;
	m.id1=c;
	m.seat1=d;
	if(n.id==m.id1){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	string n1={0};
	string m1={0};
	for(int i=0;i<=1;i++){
		n1[i]=n.seat[i];
		m1[i]=m.seat1[i];
	}
	if(n1==m1){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	if(n.seat[2]>='A'&&n.seat[2]<='C'&&m.seat1[2]>='A'&&m.seat1[2]<='C'||n.seat[2]>='D'&&n.seat[2]<='F'&&m.seat1[2]>='D'&&m.seat1[2]<='F'){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	if(n.seat[2]+1==m.seat1[2]){
		cout<<1;
	}else if(n.seat[2]-1==m.seat1[2]){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
} 
