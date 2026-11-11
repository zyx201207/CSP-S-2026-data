#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
bool b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	if(s1.size()==s3.size()){
		for(int i=0;i<s1.size();i++){
			if(s1[i]!=s3[i]){
				cout<<"0000";
				b=1;
				return 0;
			}
		}
	}else{
		cout<<"0000";
		return 0;
	}
	int num1=(s2[0]-'0')*10+(s2[1]-0);
	int num2=(s4[0]-'0')*10+(s4[1]-0);
	if(num1!=num2){
		cout<<"1000";
		return 0;
	}
	if(!(s2[2]<='C'&&s4[2]<='C')&&!(s2[2]>='D'&&s4[2]>='D')){
		cout<<"1100";
		return 0;
	}
	if(s2[2]+1==s4[2]||s2[2]-1==s4[2]){
		cout<<"1111";
		return 0;
	}
	cout<<"1110";
	return 0;
}
