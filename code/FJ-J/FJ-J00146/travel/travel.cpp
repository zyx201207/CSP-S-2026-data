#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	char s1[8],s2[7];
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		if(s1[0]==s2[0] && s1[1]==s2[1]){
			cout<<1;
			if((s1[2]+s2[2])==131 || (s1[2]+s2[2])==132 ){
				cout<<1;
				if((s1[2]-s2[2])==1 || (s2[2]-s1[2])==1){
					cout<<1;
				}
				else{
					cout<<0;
				}
			}
			else if((s1[2]+s2[2])==133 && s1[2]!='A' && s2[2]!='A'){
				cout<<1;
				if((s1[2]-s2[2])==1 || (s2[2]-s1[2])==1){
					cout<<1;
				}
				else{
					cout<<0;
				}
			}
			else if((s1[2]+s2[2])==138){
				cout<<"1";
				if((s1[2]-s2[2])==2 || (s2[2]-s1[2])==2){
					cout<<1;
				}
				else{
					cout<<0;
				}
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	
}
