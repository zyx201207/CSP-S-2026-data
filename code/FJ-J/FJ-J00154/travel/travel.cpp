#include<bits/stdc++.h >
using namespace std;
bool o(int x1,int x2,int y1,int y2){
	if(x1==y1&&x2==y2){
		return true;
	}
	else{
		return false;
	}
}
bool p(int x1,int y1){
	if(((x1<'D')&&(y1<'D'))||((x1>='D')&&(y1>='D'))){
		return true;
	}
	else{
		return false;
	}
} 
bool m(int x1,int y1){
	if(max(x1,y1)-min(x1,y1)==1){
		return true;
	}
	else{
		return false;
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string ax,ay,bx,by;
	cin>>ax>>ay>>bx>>by;
	if(ax==bx){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if((ax==bx)&&o(ay[0],ay[1],by[0],by[1])){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if((ax==bx)&&o(ay[0],ay[1],by[0],by[1])&&p(ay[2],by[2])){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if((ax==bx)&&o(ay[0],ay[1],by[0],by[1])&&p(ay[2],by[2])&&m(ay[2],by[2])){
		cout<<1;
	}
	else{
		cout<<0;
	}
}
