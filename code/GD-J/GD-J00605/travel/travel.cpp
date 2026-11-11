#include<bits/stdc++.h>
using namespace std;
string cx1,cx2,cp1,cp2;
char a[5]={'A','B','C','D','F'};
set<char>s;
bool f(){
	if((s.count(cp1[2])&&s.count(cp2[2]))||(!s.count(cp1[2])&&!s.count(cp2[2]))) return true;
	else return false;
}
bool f2(){
	for(int i=0;i<4;i++){
		if((cp1[2]==a[i]&&cp2[2]==a[i+1])||(cp2[2]==a[i]&&cp1[2]==a[i+1])) return true;
	}
	return false;
}
int main(){
	s.insert('D');
	s.insert('F');
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cx1>>cp1>>cx2>>cp2;
	if(cx1==cx2){
		cout<<1;
	}else{
		cout<<0;
	}
	if(cp1[0]==cp2[0]&&cp1[1]==cp2[1]&&cx1==cx2){
		cout<<1;
	}else{
		cout<<0;
	}
	if(f()&&cp1[0]==cp2[0]&&cp1[1]==cp2[1]&&cx1==cx2){
		cout<<1;
	}else{
		cout<<0;
	}
	if(f2()&&cp1[0]==cp2[0]&&cp1[1]==cp2[1]&&cx1==cx2&&f()){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
