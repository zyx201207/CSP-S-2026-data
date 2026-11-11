//GZ-J00516 陈载烁阳 兴义市弘毅中学 
#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool pai(string a,string b){
	for(int i=0;i<=1;i++){
		if(a[i]!=b[i]) return false; 
	}
	return true;
}
bool ce(string a,string b){
	if(a[2]=='A'||a[2]=='B'||a[2]=='C'){
		return b[2]=='A'||b[2]=='B'||b[2]=='C';
	}
	else return  b[2]=='D'||b[2]=='F';
}
bool ling(string a,string b){
	if(a[2]=='D'||a[2]=='F') return b[2]=='D'||b[2]=='F';
	if(b[2]=='D'||b[2]=='F') return a[2]=='D'||a[2]=='F';
	else if(a[2]=='B') return b[2]=='A'||b[2]=='C';
	else if(b[2]=='B') return a[2]=='A'||a[2]=='C';
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	
	
	if(c1==c2){
		cout<<"1";
      if(pai(s1,s2)){
      	cout<<"1";
      	if(ce(s1,s2)){
      		cout<<"1";
      		if(ling(s1,s2)) cout<<"1";
      		   else cout<<"0";
		  } 
      	else {
      		cout<<"00";
		  }
	  }
else {
	cout<<"000";
  }
	}
	else {
		cout<<"0000";
	}
	
	
	return 0;
} 
