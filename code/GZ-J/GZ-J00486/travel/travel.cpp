#include<iostream>
#include<cstring>

using namespace std;
char l1[3]={'A','B','C'};
char l2[2]={'D','F'};
int main(){
    freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	if(s1[0]!=s2[0]||s1[1]!=s2[1]){
		cout<<"1000";
		return 0;
	}//same car/line
	if((s1[2]=='D'&&s1[2]=='F')||(s1[2]=='D'&&s1[2]=='F')){
		cout<<"1111";
		return 0;
	}
	if(s1[2]=='D'||s1[2]=='F'||s2[2]=='D'||s2[2]=='F'){
		cout<<"1100";
	}

	if(s1[2]=='A'&&s2[2]=='B'||s1[2]=='B'&&s2[2]=='A'){
		cout<<"1111";
		return 0;
	}
	if(s1[2]=='C'&&s2[2]=='B'||s1[2]=='B'&&s2[2]=='C'){
		cout<<"1111";
		return 0;
	}
	if(s1[2]=='A'&&s2[2]=='C'||s1[2]=='C'&&s2[2]=='A'){
		cout<<"1111";
		return 0;
	}
	cout<<"1110";
	return 0;
}
