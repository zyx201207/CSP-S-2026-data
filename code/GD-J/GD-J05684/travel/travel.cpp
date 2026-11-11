#include <bits/stdc++.h>
using namespace std;
string a[4];
int qwq(string a){
	if(a[0]=='0'){
		return a[1]-'0';
	}
	else{
		return a[1]-'0'+10;
	}
}

int wqw(string a){
	return a[2]-'A'+1;
}

bool ppp(int a,int b){
	if(a<=3 && b<=3){
		return true;
	}
	if(a>=4 && b>=4){
		return true;
	}
	return false;
}

bool one(){
	if(qwq(a[0])==qwq(a[2])){
		cout<<"1";
		return true;
	}else{
		cout<<"0000";
		return false;
	}
}
bool two(){
	if(qwq(a[1])==qwq(a[3])){
		cout<<"1";
		return true;
	}else{
		cout<<"000";
		return false;
	}
}
bool three(){
	if(ppp(wqw(a[1]),wqw(a[3]))){
		cout<<"1";
		return true;
	}else{
		cout<<"00";
		return false;
	}
}
bool four(){
	if(wqw(a[1])==wqw(a[3])+1){
		cout<<"1";
		return true;
	}
	if(wqw(a[1])==wqw(a[3])-1){
		cout<<"1";
		return true;
	}
	else{
		cout<<"0";
		return false;
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=0;i<4;i++){
		cin>>a[i];
	}
	if(!one()){
		return 0;
	}
	if(!two()){
		return 0;
	}
	if(!three()){
		return 0;
	}
	if(!four()){
		return 0;
	}
	return 0;
}
