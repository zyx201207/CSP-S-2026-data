#include<bits/stdc++.h> 
using namespace std;
char a,b,c,d,a1,e,b1,c1,d1,e1;
string s;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a>>b >>c>>d>>e;;
	cin >> a1>>b1 >>c1>>d1>>e1;
	if(a!=a1||b!=b1){
		cout<<0;
		cout << 0;
		cout << 0;
		cout << 0;
		return 0;
	}
	else{
		s=s+'1';
	}
	
	if(c==c1&&d==d1){
		s=s+'1';
	}
	else{
		cout<<s;
		cout << 0;
		cout << 0;
		cout << 0;
		return 0;
	}
	
	if((e=='A'&&e1=='B')||  (e=='B'&&e1=='A')|| (e=='B'&&e1=='C')|| (e=='C'&&e1=='B')|| (e=='C'&&e1=='A')|| (e=='A'&&e1=='C')|| (e=='D'&&e1=='F')||   (e=='F'&&e1=='D')    ){
		s+='1';
	}
	else{
		cout << s;
		cout << 0;
		cout << 0;
		return 0;
	}
	if((e=='A'&&e1=='B')||  (e=='B'&&e1=='A')||(e=='B'&&e1=='C')|| (e=='C'&&e1=='B')||(e=='D'&&e1=='F')||   (e=='F'&&e1=='D')){
		s=s+'1';
	}
	else if(e=='A'&&e1=='C'||e=='C'&&e1=='A'){
		cout<<s;
		cout << 0;
		return 0;
	}
	else
	{
		cout << 1111;
		return 0;
	}
	cout << s;
	for(int i = 1;i <= (4-s.size());i++){
		cout<<0;
	}
	
	return 0;
}
