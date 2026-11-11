#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	cout<<1;
	int typ;
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		typ=1;
		cout<<1;
	}else{
		typ=0;
		cout<<0;
	}
	int a,b;
	if(s1[2]<='C'){
		a=1;
	}else{
		a=0;
	}
	if(s2[2]<='C'){
		b=1;
	}else{
		b=0;
	}
	if(a==b&&typ){
		cout<<1;
	}else{
		cout<<0;
	}
	if(abs(int(s1[2])-int(s2[2]))==1&&a==b&&typ){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
