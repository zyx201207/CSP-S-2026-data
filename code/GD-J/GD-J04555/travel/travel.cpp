#include<bits/stdc++.h>
using namespace std;
int a(int g){
	if(g<68){
		return 1;
	}else{
		return 0;
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int x=0,y=0;
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	x=a(s1[2]);
	y=a(s2[2]);
	if(x==y){
		cout<<"1";
	}else{
		cout<<"00";
		return 0;
	}
	if(s1[2]+1==s2[2]||s1[2]-1==s2[2]){
		cout<<"1";
	}else{
		cout<<"0";
	}
	return 0;
}
