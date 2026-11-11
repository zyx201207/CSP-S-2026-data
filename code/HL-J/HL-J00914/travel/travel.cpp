#include<bits/stdc++.h>
using namespace std;
char s1[110],s2[110],x,y;
int n,m,a,b;
bool check(){
	if((x>='A'&&x<='C'&&y>='A'&&y<='C')||(x>='D'&&x<='F'&&y>='D'&&y<='F')){
		return true;
	}
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>s1>>m>>s2;
	x=s1[2],y=s2[2];
	a=10*(s1[0]-'0')+(s1[1]-'0');
	b=10*(s2[0]-'0')+(s2[1]-'0');
	if(n!=m){
		cout<<"0000";
		return 0;
	}
	else{
		cout<<1;
		if(a==b){
			cout<<1;
			if(check()){
				cout<<1;
				if(abs(x-y)==1&&check()) cout<<1;
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	return 0;
}