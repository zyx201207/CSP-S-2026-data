#include<bits/stdc++.h>
using namespace std;
string c1,c2;
int a,b,c,d,x,y;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>c1>>b>>c2;
	c=(c1[0]-'0')*10+c1[1]-'0';
	d=(c2[0]-'0')*10+c2[1]-'0';
	x=c1[2]-'A'+1;
	y=c2[2]-'A'+1;
	if(x==6){
		x--;
	}
	if(y==6){
		y--;
	}
	if(a==b){
		cout<<1;
		if(c==d){
			cout<<1;
			if((x<=3 && y<=3) || (x>3 && y>3)){
				cout<<1;
				if(abs(x-y)==1){
					cout<<1;
				}else{
					cout<<"0";
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
} 
