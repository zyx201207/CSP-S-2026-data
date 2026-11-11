#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool f1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<"1";
			if(s1[2]=='D'){
				f1=s2[2]=='F';
			}else if(s1[2]=='F'){
				f1=s2[2]=='D';
			}else if(s1[2]=='C'){
				f1=s2[2]=='B'||s2[2]=='A';
			}else if(s1[2]=='B'){
				f1=s2[2]=='C'||s2[2]=='A';
			}else{
				f1=s2[2]=='C'||s2[2]=='B';
			}
			if(f1){
				cout<<"1";
				if((s1[2]=='F'&&s2[2]=='D')||(s1[2]=='D'&&s2[2]=='F')||
			       (s1[2]=='C'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='A')||
			       (s1[2]=='B'&&s2[2]=='C')||(s1[2]=='A'&&s2[2]=='B')){
			       	cout<<"1";
				}else{
					cout<<"0";
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
