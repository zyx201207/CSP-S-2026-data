#include<bits/stdc++.h>
using namespace std;
bool f(char c){
	if(c=='A'||c=='B'||c=='C'){
		return 0;
	}
	else{
		return 1;
	}
}
int w(char c){
	if(c=='F'){
		return 5;
	}
	return (c-'A')+1;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int x,xx,y,yy;
	char c,cc;
	cin>>x>>xx>>c>>y>>yy>>cc;
//	cout<<x<<" "<<xx<<" "<<c<<" "<<y<<" "<<yy<<" "<<cc;
	if(x==y){
		cout<<1; 
	}
	else{
		cout<<0;
	}
	if(x==y&&xx==yy){
		cout<<1; 
	}
	else{
		cout<<0;
	}
	if(x==y&&xx==yy&&f(c)==f(cc)){
		cout<<1; 
	}
	else{
		cout<<0;
	}
	if(x==y&&xx==yy&&f(c)==f(cc)&&abs(w(c)-w(cc))==1){
		cout<<1; 
	}
	else{
		cout<<0;
	}
} 
