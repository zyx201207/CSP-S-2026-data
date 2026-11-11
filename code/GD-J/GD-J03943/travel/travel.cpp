#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
string c1,c2,s1,s2;
int a1,a2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>c1>>s1>>c2>>s2;
	a1=10*s1[0]-'0'+s1[1]-'0';
	a2=10*s2[0]-'0'+s2[1]-'0';
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}else{
		cout<<'1';
	}
	if(a1!=a2){
		cout<<"000";
		return 0;
	}else{
		cout<<'1';
	}
	if(s1[2]>='A' && s1[2]<='C'){
		if(s2[2]>='A' && s2[2]<='C'){
			cout<<'1';
		}else{
			cout<<"00";
			return 0;
		}
	}else if(s1[2]>='E' && s1[2]<='F'){
		if(s2[2]>='E' && s2[2]<='F'){
			cout<<"11";
			return 0;
		}else{
			cout<<"00";
			return 0;
		}
	}if(abs(int(s1[2]-s2[2]))==1){
		cout<<'1';
	}else{
		cout<<'0';
	}
	return 0;
	
}

