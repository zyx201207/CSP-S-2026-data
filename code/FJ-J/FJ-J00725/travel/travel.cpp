#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	bool x,y,z;
	cin>>c1>>s1>>c2>>s2;
	if(c1 == c2){
		cout<<1;
		x=true;
	}else{
		cout<<0;
		x=false;
	}
	if(x == true){
		if(s1[0]==s2[0] && s1[1]==s2[1]){
			cout<<1;
			y=true;
		}else{
			cout<<0;
			y=false;
		}
	}else{
		cout<<0;
	}
	if(x==true && y==true){
		if(int(s1[2])<=67&&int(s2[2])<=67 || int(s1[2])>=68&&int(s2[2])>=68){
			cout<<1;
			z=true;
		}else{
			cout<<0;
			z=false;
		}
	}else{
		cout<<0;
	}
	if(x==true && y==true && z==true){
		if(int(s1[2])-int(s2[2])==1 || int(s1[2])-int(s2[2])==-1){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		cout<<0;
	}
	return 0;
}
