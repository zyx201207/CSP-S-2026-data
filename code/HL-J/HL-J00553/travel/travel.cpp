#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	if(s1[1]==s3[1]){
		cout<<"1";
		if(s2[0]==s4[0]&&s2[1]==s4[1]){
			cout<<"1";
			if(s2[2]<='C'&&s4[2]<='C'){
				int x=s2[2]-'A',y=s4[2]-'A';
				int a=max(x,y),b=min(x,y);
				if(a-1==b){
					cout<<"11";
					return 0;
				}
				else{
					cout<<"10";
					return 0;
				}
			}
			else if(s2[2]<='F'&&s4[2]<='F'&&s2[2]>='D'&&s4[2]>='D'){
				cout<<"11";
				return 0;
			}
			else{
				cout<<"00";
				return 0;
			}
		}
		else{
			cout<<"000";
			return 0;
		}
	}
	else{
		cout<<"0000";
		return 0;
	}
	return 0;
}
