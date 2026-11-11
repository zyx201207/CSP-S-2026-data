#include<bits/stdc++.h>
using namespace std;
struct node{
	int xiang,pai;
	char wei;
};
int main(){
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	node x,y;
	if(a[0]=='0'){
		x.xiang=a[1]-'0';
	}
	if(a[0]=='1'){
		x.xiang=10+a[1]-'0'; 
	}
	if(c[0]=='0'){
		y.xiang=c[1]-'0';
	}
	if(c[0]=='1'){
		y.xiang=10+c[1]-'0'; 
	}
	if(b[0]=='0'){
		x.pai=b[1]-'0';
	}
	if(b[0]=='1'){
		x.pai=10+b[1]-'0'; 
	}
	if(d[0]=='0'){
		y.pai=d[1]-'0';
	}
	if(d[0]=='1'){
		y.pai=10+d[1]-'0'; 
	}
	x.wei=b[2];
	y.wei=d[2];
	if(x.xiang==y.xiang){
		cout<<1;
		if(x.pai==y.pai){
			cout<<1;
			if((x.wei=='A'||x.wei=='B'||x.wei=='C')&&(y.wei=='A'||y.wei=='B'||y.wei=='C')){
				cout<<1;
				if((x.wei=='A'&&y.wei!='B')||(x.wei=='C'&&y.wei!='B')){
					cout<<0;
				}
				else{
					cout<<1;
				}
			}
			if((x.wei=='D'||x.wei=='E')&&(y.wei=='D'||y.wei=='E')){
				cout<<11;
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
}
