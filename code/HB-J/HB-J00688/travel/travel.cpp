#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2,a1,b1,a2,b2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	a1=s1[0]+s1[1];
	b1=s2[0]+s2[1];
	a2=s1[2];
	b2=s2[2];
	if(c1==c2){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	if(a1==b1){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	if(a2>="A"&&a2<="C"&&b2>="A"&&b2<="C"){
		cout<<"1";
	}else if(a2>="D"&&a2<="F"&&b2>="D"&&b2<="F"){	
		cout<<"1";
	}else{
		cout<<"00";
		return 0;
	}
	
	if(a2>="A"&&a2<="C"&&b2>="A"&&b2<="C"&&((a2=="A"&&b2=="B")||(a2=="B"&&b2=="A")||(a2=="B"&&b2=="C")||(a2=="C"&&b2=="B"))){
		cout<<"1";
	}else if(a2>="D"&&a2<="F"&&b2>="D"&&b2<="F"&&((a2=="D"&&b2=="F")||(a2=="F"&&b2=="D"))){	
		cout<<"1";
	}else{
		cout<<"0";
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
	
}
