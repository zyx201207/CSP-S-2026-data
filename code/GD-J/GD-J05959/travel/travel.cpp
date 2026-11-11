#include<bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2,a3,b3;
int a,aa,b,bb;
bool check(){
	int x,y;
	if(a2[2]=='A'||a2[2]=='B'||a2[2]=='C'){
		x=1;
	}
	else{
		x=0;
	}
	if(b2[2]=='A'||b2[2]=='B'||b2[2]=='C'){
		y=1;
	}
	else{
		y=0;
	}
	return x==y;
}
int turn(string p){
	int p1=0;
	for(int i=0;i<p.size();i++){
		p1*=10;
		p1+=p[i]-48;
	}
	return p1;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>b1>>b2;
	a=turn(a1);
	a3=a2[0]+a2[1];
	aa=turn(a3);
	b=turn(b1);
	b3=b2[0]+b2[1];
	bb=turn(b3);
	if(a==b){
		cout<<1;
		if(aa==bb){
			cout<<1;
			if(check()){
				cout<<1; 
				if(b2[2]-a2[2]==1||b2[2]-a2[2]==-1){
					cout<<1<<endl;
				}
				else{
					cout<<0<<endl;
				}
			}
			else{
				cout<<"00"<<endl;
			}
		}
		else{
			cout<<"000"<<endl;
		}
	}
	else{
		cout<<"0000"<<endl;
	}
	return 0;
}
