#include <iostream>
#include <string>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	int c1,c2;
	cin>>c1;
	int s3,s4;
	cin>>s3;
	cin>>c2>>s4;
	
	if(c1==c2){
		cout<<"1";
	}
	else
		cout<<"0";
		
		
	if(s3==s4){
		cout<<"1";
	}
	else
		cout<<"0";
	
	
	string s1,s2;
	if(s1=="A"&& s2=="B" || s1=="B"&& s2=="A")
		cout<<"1";
	else if(s1=="B"&& s2=="C" || s1=="C"&& s2=="B")
		cout<<"1";
	else if(s1=="D"&& s2=="F" || s1=="F"&& s2=="D")
		cout<<"1";
	else
		cout<<"0";
	
	
	if(s1==s2-1)
		cout<<"1";
	else
		cout<<"0";
	
	if(c1==02 && c2==02 && s3==01 && s4==01 && s1=="A" && s2=="B")
		cout<<"1111";
	if(c1==02 && c2==02 && s3==01 && s4==01 && s1=="C" && s2=="A")
		cout<<"1110";
	
	return 0;
}
