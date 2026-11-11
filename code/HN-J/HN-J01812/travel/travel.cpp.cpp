#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","r",stdout);
	int c1,c2; 
	string s1,s2;
	cin>>c1>>s1>>c2>>s2; 
	if(c1==c2){
		cout<<"1";
		if(s1[1]==s2[1]&&s2[2]==s2[2]){
			cout<<"1";
			if(s1[3]==s2[3]||'C'>=s1[3]>='A'&&'C'>=s2[3]>='A'||'E'>=s1[3]>='D'&&'E'>=s2[3]>='D'){
				cout<<"1";
				if((s1[3]-1)==s1[3]||(s1[3]+1)==s1[3]){
					cout<<"1";
				}
				else cout<<"1110";
			}
			 
			else {
				cout<<"0";
				if((s1[3]-1)==s1[3]||(s1[3]+1)==s1[3]){
					cout<<"1";
			}
			else cout<<"0";
		}
	} 
		else{
			cout<<"0";
			if(s1[3]==s2[3]||'C'>=s1[3]>='A'&&'C'>=s2[3]>='A'||'E'>=s1[3]>='D'&&'E'>=s2[3]>='D'){
				cout<<"10";
		}
		else cout<<"00";
	}
	} 
	if(c1!=c2) cout<<"0000";
	 
	return 0;
}
