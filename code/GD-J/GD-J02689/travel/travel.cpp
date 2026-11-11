#include <bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int fl=0,fl2=0,fl3=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	//cout<<"s1="<<s1<<"s2="<<s2;
	if(c1==c2){
		cout<<1;
		fl=1;
	}else{
		cout<<0;
	}
	if(fl&&s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<1;
		fl2=1;
	}else{
		cout<<0;
	}
	if(fl2&&((s1[2]<='F'&&s2[2]<='F'&&s1[2]>='D'&&s2[2]>='D')||(s1[2]<='C'&&s2[2]<='C'&&s1[2]>='A'&&s2[2]>='A'))){
		cout<<1;
		fl3=1;
	}else{
		cout<<0;
	}
//	cout<<"nm="<<int(s1[2])-int(s2[2])<<endl;
	if(fl3&&((int(s1[2])-int(s2[2])==1)||(int(s1[2])-int(s2[2])==-1))){
		cout<<1;
	}else{
		cout<<0;
	}
} 
