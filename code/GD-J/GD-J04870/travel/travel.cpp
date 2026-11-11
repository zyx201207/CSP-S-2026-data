#include<bits/stdc++.h>
using namespace std;
string c_1,s_1,c_2,s_2;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c_1>>s_1>>c_2>>s_2;
	if(c_1==c_2)cout<<"1";
	else {
		cout<<"0000"<<endl;
		return 0;
	}
	if(s_1[0]==s_2[0]&&s_1[1]==s_2[1])cout<<"1";
	else{
		cout<<"000"<<endl;
		return 0;
	}
	if(s_1[2]-'A'<3&&s_2[2]-'A'<3)cout<<"1";
	else if(s_1[2]-'A'>=3&&s_2[2]-'A'>=3){
		cout<<"11"<<endl;
		return 0;
	}
	else{
		cout<<"00"<<endl;
		return 0;
	}
	if(s_1[2]-'A'<2&&s_2[2]-'A'<2)cout<<"1"<<endl;
	else if(s_1[2]-'A'>=2&&s_2[2]-'A'>=2) cout<<"1"<<endl;
	else cout<<"0"<<endl;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
