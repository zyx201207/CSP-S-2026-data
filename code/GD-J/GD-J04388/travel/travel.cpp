#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000"<<endl;
	}
	else if(s1[0]!=s2[0]||s1[1]!=s2[1]){
		cout<<"1000"<<endl; 
	}
	else if(s1[2]-'A'<3&&s2[2]-'A'<3||s1[2]-'A'>=3&&s2[2]-'A'>=3){
		if(abs(int(s1[2]-s2[2]))<2){
			cout<<"1111"<<endl;
		}
		else{
			cout<<"1110"<<endl;
		}
	}
	else{
		cout<<"1100"<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
