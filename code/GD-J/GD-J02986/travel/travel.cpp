#include<bits/stdc++.h>
using namespace std;
int n;
int c[3];
char a[105],b[105];
bool check(char g,char h){
	if(g<='C'&&h<='C'){
		return 1;
	}if(g<='F'&&h<='F'&&g>='D'&&h>='D'){
		return 1;
	}else{
		return 0;
	}
}
bool checkk(char g,char h){
	if(g=='D'&&h=='F'){
		return 1;
	}
	if(g-h==1||g-h==-1){
		return 1;
	}else{
		return 0;
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c[1];
	cin>>a[1]>>a[2]>>a[3];
	cin>>c[2];
	cin>>b[1]>>b[2]>>b[3];
	
	if(c[1]==c[2]){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	if(a[1]==b[1]&&a[2]==b[2]){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}if(check(a[3],b[3])){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}if(checkk(a[3],b[3])){
		cout<<1;
		return 0;
	}else{
		cout<<0;
	}
	return 0;
}
