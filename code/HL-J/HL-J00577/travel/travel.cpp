#include<bits/stdc++.h>
using namespace std;
int c1,c2,n,m;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
	}else if(s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<"11";
		if((s1[2]-'A'==3&&s2[2]-'A'==5)||(s1[2]-'A'==5&&s2[2]-'A'==3)||(s2[2]-'A'==3&&s1[2]-'A'==5)||(s2[2]-'A'==5&&s1[2]-'A'==3)||(s1[2]-'A'<=2&&s1[2]-'A'>=0&&s2[2]-'A'>=0&&s2[2]-'A'<=2)){
			cout<<"1";
			if(s1[2]+1==s2[2]||s1[2]-1==s2[2]){
				cout<<"1";
			}else{
				cout<<"0";
			}
		}else{
			cout<<"00";
		} 
	}else{
		cout<<"1000";
	}
	
	return 0;
} 
