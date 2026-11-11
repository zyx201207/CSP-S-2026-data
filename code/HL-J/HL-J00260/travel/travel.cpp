#include<bits/stdc++.h>
using namespace std;
char s1[4],s2[4];
int c1,c2;
bool flag=false;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1;
    for(int i=1;i<=3;i++){
    	cin>>s1[i];
	}
	cin>>c2;
	for(int i=1;i<=3;i++){
		cin>>s2[i];
	}
    if(c1==c2&&c1==c2){
    	cout<<"1";
    	if(s1[1]==s2[1]&&s1[2]==s2[2]){
    		flag=true;
		}
	}else{
		cout<<"0000";
		return 0;
	}
	if(flag){
		cout<<"1";
		if(s1[3]=='A'&&s2[3]=='B'){
			cout<<"11";
		}else if(s1[3]=='B'&&s2[3]=='A'){
			cout<<"11";
		}else if(s1[3]=='B'&&s2[3]=='C'){
			cout<<"11";
		}else if(s1[3]=='C'&&s2[3]=='B'){
			cout<<"11";
		}else if(s1[3]=='D'&&s2[3]=='F'){
			cout<<"11";
		}else if(s1[3]=='F'&&s2[3]=='D'){
			cout<<"11";
		}else if(s1[3]=='A'&&s2[3]=='C'){
			cout<<"10";
		}else if(s1[3]=='C'&&s2[3]=='A'){
			cout<<"10";
		}else{
			cout<<"00";
		}
	}else{
		cout<<"000";
	}
	return 0;
}