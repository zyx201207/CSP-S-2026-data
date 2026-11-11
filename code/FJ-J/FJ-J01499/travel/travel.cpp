#include <bits/stdc++.h>
using namespace std;
double t1,t2;
string s1,s2,l1,l2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>t1>>l1>>t2>>l2;
	s1=l1[2];
	s2=l2[2];
	if(t1==t2){
		cout<<1;
	}else{
		cout<<0000;
		return 0;
	}
	if(l1[0]==l2[0]&&l1[1]==l2[1]){
		cout<<1;
	}else{
		cout<<1000;
		return 0;
	}
	if(s1<="c"&&s2<="c"){
		if((s1=="c"&&s2=="a")||(s1=="a"&&s2=="c")){
			cout<<10;
		}
		else{
			cout<<11;
		}
	}
	else if(s1>="d"&&s2>="d"){
		cout<<11;
	}
	else{
		cout<<00;
	}
	return 0;
} 
