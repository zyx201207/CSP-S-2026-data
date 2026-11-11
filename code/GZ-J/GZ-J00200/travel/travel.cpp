//GZ-J00200 观山湖中学 马志翔  
#include<bits/stdc++.h>
using namespace std;
void ji(){
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	string s;
	if(s1==s3){
		s+='1';
		if(s2[0]==s4[0]&&s2[1]==s4[1]){
			s+='1';
			if((s2[2]=='A'||s2[2]=='B'||s2[2]=='C')&&(s4[2]=='D'||s4[2]=='F')){
				cout<<"1100"<<endl;
				return;
			}else{
				s+='1';
				if((s2[2]=='D'&&s4[2]=='F')||s2[2]=='F'&&s4[2]=='D'){
					s+='1';
				}else if(abs(s2[2]-s4[2])==1){
					s+='1';
				}else{
					cout<<"1110"<<endl;
					return;
				}
			}
		}else{
			cout<<"1000"<<endl;
			return;
		}
	}else{
		cout<<"0000"<<endl;
		return;
	}
	cout<<s<<endl;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int t=1;
    //cin>>t;
	while(t--){
		ji();
	} 
}
