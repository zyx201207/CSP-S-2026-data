#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int zhuan(string s){
	int ans=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9')
			ans=(int)(s[i]-'0')+ans*10;
	}
	return ans;
}
int no(string x){
	return (int)(x[x.size()-1]-'A');
}
bool zhuan1(string x,string y){
	int q=no(x),q1=no(y);
	if((0<=q&&q<=2&&0<=q1&&q1<=2)||(3<=q&&q<=4&&3<=q1&&q1<=4))
		return 1;
	else
		return 0;
}
bool zhuan2(string x,string y){
	int q=no(x),q1=no(y);
	if(abs(q-q1)==1)
		return 1;
	else
		return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	bool f=0,f1=0;
	//op1
		if(c1==c2){
			cout<<1;
			f=1;
		}
		else{
			cout<<0;
		}	
	//op2
		if(f&&zhuan(s1)==zhuan(s2)){
			cout<<1;
			f1=1;
		}
		else{
			cout<<0;	
		}
	//op3
		if(f&&f1&&zhuan1(s1,s2))
			cout<<1;
		else
			cout<<0;
	//op4
		if(f&&f1&&zhuan1(s1,s2)&&zhuan2(s1,s2))
			cout<<1;
		else
			cout<<0;
	return 0;
}

