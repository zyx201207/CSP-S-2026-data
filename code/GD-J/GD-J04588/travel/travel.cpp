#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,a,b;
int x,y;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	a=s1[0]+s1[1],b=s2[0]+s2[1];
	if(a==b){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	if(s1[2]>='A'&&s1[2]<='C'){
		if(s2[2]>='A'&&s2[2]<='C'){
			cout<<"1";
		}else{
			cout<<"00";
			return 0;
		}
	}else{
		if(s2[2]=='F'||s2[2]=='D'){
			cout<<"1";
		}else{
			cout<<"00";
			return 0;
		}
	}
	x=s1[2]-'A',y=s2[2]-'A';
	if(max(x,y)-min(x,y)==1){
		cout<<"1";
	}else{
		cout<<"0";
	}
	return 0;
}

