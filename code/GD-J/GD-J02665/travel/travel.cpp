#include<bits/stdc++.h>
using namespace std;
bool ri(char a,char b){
	if(a>='A'&&a<='C'){
	   if(b>='A'&&b<='C') return true;	
	}
	else{
	  if(b>='D'&&b<='F') return true;	
	}
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1;
	//小R的车票上的车厢号座位号
	string c2,s2;
	//小X的车票上的车厢号座位号
	cin>>c1>>s1>>c2>>s2;
	int sum=(int)s1[2]-s2[2];
	if(c1==c2){
	  cout<<'1';
	  if(s1[0]==s2[0]&&s1[1]==s2[1]){
	  	cout<<'1';	
	  	if(ri(s1[2],s2[2])){
	  		cout<<'1';
	  		if(abs(sum)==1) cout<<'1';
	  		else cout<<'0';
		} 
	  	else cout<<"00";
	  }
	  else cout<<"000";
	}
	else{
		cout<<"0000";
	}
    return 0;
} 
