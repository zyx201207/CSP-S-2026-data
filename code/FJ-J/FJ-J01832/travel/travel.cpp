#include<bits/stdc++.h>
using namespace std;

string c1,s,c2,s2;

int main(){
	freopen("r","travel.in",stdin);
	cin>>c1>>s>>c2>>s2;
	if(c1==c2){
		cout<<1;
//		cout<<"  q1"<<endl;
	}
	else{
		cout<<0;
//		cout<<"  q1"<<endl;
	}
	if(c1==c2&&s[0]==s2[0]&&s[1]==s2[1]){
		cout<<1;
//		cout<<"  q2"<<endl;
	}
	else{
		cout<<0;
//		cout<<"  q2"<<endl;
	}
	if(c1==c2&&s[0]==s2[0]&&s[1]==s2[1]  && ( (s[2]>='A'&&s[2]<='C'&&s2[2]>='A'&&s2[2]<='C') || (s[2]>='D'&&s[2]<='E'&&s2[2]>='D'&&s2[2]<='E') )){
		cout<<1;
//		cout<<"  q3"<<endl;
	}
	else{
		cout<<0;
//		cout<<"  q3"<<endl;
	}
	if(c1==c2&&s[0]==s2[0]&&s[1]==s2[1]  && ( (s[2]>='A'&&s[2]<='C'&&s2[2]>='A'&&s2[2]<='C') || (s[2]>='D'&&s[2]<='E'&&s2[2]>='D'&&s2[2]<='E') )&&abs(int(s2[2])-int(s[2]))==1){
		cout<<1;
//		cout<<"  q4"<<endl;
	}
	else{
		cout<<0;
//		cout<<"  q4"<<endl;
	}
	freopen("w","travel.out",stdout);
	return 0;
}
