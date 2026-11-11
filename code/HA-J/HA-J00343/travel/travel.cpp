#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<1;
			bool f1=s1[2]-'A'<=2 && s2[2]-'A'<=2;
			bool f2=s1[2]-'A'>=3 && s2[2]-'A'>=3;
			if(f1){
				cout<<1;
				if(s1[2]=='B'||s2[2]=='B'){
					cout<<1;
				}
				else cout<<0;
			}
			else if(f2){
				cout<<"11";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
} 
