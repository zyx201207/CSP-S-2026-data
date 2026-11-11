#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
bool a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int x=0,y=0;
	for(int i=0;i<2;i++){
		x=x*10+c1[i]-'0';
		y=y*10+c2[i]-'0';
	}
	if(x==y){
		a=1;
	}else{
		cout<<"0000";
		return 0;
	}
	x=0,y=0;
	for(int i=0;i<2;i++){
		x=x*10+s1[i]-'0';
		y=y*10+s2[i]-'0';
	}
	if(x==y) b=1;
	else{
		cout<<1000;
		return 0;	
	} 
	char p=s1[2],q=s2[2];
	if(p<='C'&&q<='C' || p>'C'&&q>'C') c=1;
	else{
		cout<<1100;
		return 0;
	}
	if(abs(int(q-p))==1&&p+q!='C'+'D') d=1;
	else d=0;
	cout<<a<<b<<c<<d;
	return 0;
}
