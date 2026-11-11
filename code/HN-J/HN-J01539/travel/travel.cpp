#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,a,b;
	cin>>a>>s1>>b>>s2;
	if(a[0]==b[0]&&a[1]==b[1]){
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			if((s1[2]=='F'&&s2[2]=='D')||(s1[2]=='D'&&s2[2]=='F')){
				cout<<"1111";
			}
			else if(s1[2]=='F'||s2[2]=='F'||s1[2]=='D'||s2[2]=='D'){
				cout<<"1100";
			}
			else{
				if(abs(int(s1[2])-int(s2[2]))<=1){
					cout<<"1111";
				}
				else{
					cout<<"1110";
				}
			} 
		}
		else{
			cout<<"1000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
} 
