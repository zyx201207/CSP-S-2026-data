#include<bits/stdc++.h>
using namespace std;
bool x1,y1;
bool iii(string x,string y){
	if((x[2]=='A'||x[2]=='B'||x[2]=='C')&&(y[2]=='A'||y[2]=='B'||y[2]=='C')){
		return true;
	}
	if(x[2]=='D'||x[2]=='E'&&y[2]=='D'||y[2]=='E'){
		return true;
	}
	return false;
}
bool jjj(string x,string y){
	if((x[2]=='D'||x[2]=='E')&&(y[2]=='D'||y[2]=='E'))
		return true;
	if(x[2]=='A'&&y[2]=='B')
		return true;
	if(x[2]=='B'&&(y[2]=='A'||y[2]=='C'))
		return true;
	if(x[2]=='C'&&y[2]=='B')
		return true;
	return false;
}
int main(){
freopen ("travel.in","r",stdin);
freopen ("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}if(s1[1]==s2[1]){
		cout<<"1";
		if(iii(s1,s2)){
			cout<<"1";
		}else{
			cout<<"00";
			return 0;
		}
	}else{ 
		cout<<"000";
		return 0;
	}if(jjj(s1,s2)){
		cout<<"1";
	}else{
		cout<<"0";
	}
	cout<<endl;
	cout.flush();
	return 0;
}
