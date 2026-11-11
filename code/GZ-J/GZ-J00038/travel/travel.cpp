//贵阳市白云区华师一学校 刘骏轩 GZ-J00038
#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	if(c1==c2){
		cout<<1;
	}
	char s11=s1[0],s21=s2[0];
	char s12=s1[1],s22=s2[1];
	bool f=1;
	if((s11==s21)&&(s12==s22)){
		cout<<1;
	}
	else{
		cout<<0;
		f=0;
	}
	char s13=s1[2],s23=s2[2];
	if(max(s13,s23)<'D'&&min(s13,s23)<'D'&&f){
		cout<<1;
	}
	else if(max(s13,s23)=='F'&&min(s13,s23)=='D'&&f){
		cout<<1;
	}
	else{
		cout<<0;
		f=0;
	}
	if(max(s13,s23)=='F'&&min(s13,s23)=='D'&&f){
		cout<<1;
	}
	else if((max(s13,s23)-min(s13,s23)==1)&&max(s13,s23)!='D'&&f){
		cout<<1;
	}
	else{
        cout<<0;
	}
	return 0;
}
