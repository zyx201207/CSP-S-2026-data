#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	
	if(c1==c2)
		cout<<'1';
	else{
		cout<<"0000";
		return 0;
	}
	
	if(s1.substr(0,2)==s2.substr(0,2))
		cout<<'1';
	else{
		cout<<"000";
		return 0;
	}
	
	int P1=int(s1[2]-'A'),P2=int(s2[2]-'A');
	if(P1<3&&P2<3)
		cout<<'1';
	else if(P1>=3&&P2>=3){
		cout<<"11";
		return 0;
	}else{
		cout<<"00";
		return 0;
	}
	
	if(P1-1==P2||P2-1==P1){
		cout<<'1';
	}else{
		cout<<'0';
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
