#include<bits/stdc++.h>
using namespace std;

string c_1,s_1,c_2,s_2;
long long a=0,b=0;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c_1>>s_1>>c_2>>s_2;
	for(int i=0;i<c_1.size();i++){
		if(c_1[i]==c_2[i]){
			a++;
		}else{
			cout<<"0000";
			return 0;
		}
		if(a==2){
			cout<<"1";
			break;
		}
	}
	for(int i=0;i<s_1.size();i++){
		if(s_1[i]==s_2[i]){
			b++;
		}else if(i<=2){
			cout<<"000";
			return 0;
		}
		if(b==2){
			cout<<"1";
			break;
		}
	}
	if((s_1[2]=='A'||s_1[2]=='B'||s_1[2]=='C')&&(s_2[2]=='D'||s_2[2]=='F')){
		cout<<"00";
		return 0;
	}else if((s_1[2]=='D'||s_1[2]=='F')&&(s_2[2]=='A'||s_2[2]=='B'||s_2[2]=='C')){
		cout<<"00";
		return 0;
	}else if((s_1[2]=='A'||s_1[2]=='B'||s_1[2]=='C')&&(s_2[2]=='A'||s_2[2]=='B'||s_2[2]=='C')){
		cout<<"1";
		if(s_1[2]=='A'&&s_2[2]=='B'){
			cout<<"1";
			return 0;
		}else if(s_1[2]=='B'&&s_2[2]=='A'){
			cout<<"1";
			return 0;
		}else if(s_1[2]=='C'&&s_2[2]=='B'){
			cout<<"1";
			return 0;
		}else if(s_1[2]=='B'&&s_2[2]=='C'){
			cout<<"1";
			return 0;
		}else if(s_1[2]=='D'&&s_2[2]=='F'){
			cout<<"1";
			return 0;
		}else if(s_1[2]=='F'&&s_2[2]=='D'){
			cout<<"1";
			return 0;
		}else{
			cout<<"0";
			return 0;
		}
	}else if((s_1[2]=='D'||s_1[2]=='F')&&(s_2[2]=='D'||s_2[2]=='F')){
		cout<<"1";
		if(s_1[2]=='A'&&s_2[2]=='B'){
			cout<<"1";
			return 0;
		}else if(s_1[2]=='B'&&s_2[2]=='A'){
			cout<<"1";
			return 0;
		}else if(s_1[2]=='C'&&s_2[2]=='B'){
			cout<<"1";
			return 0;
		}else if(s_1[2]=='B'&&s_2[2]=='C'){
			cout<<"1";
			return 0;
		}else if(s_1[2]=='D'&&s_2[2]=='F'){
			cout<<"1";
			return 0;
		}else if(s_1[2]=='F'&&s_2[2]=='D'){
			cout<<"1";
			return 0;
		}else{
			cout<<"0";
			return 0;
		}
	}
	
	return 0;
} 
