#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char a[2],a1[3],s[2],s1[3];
	cin>>a[0]>>a[1]>>a1[0]>>a1[1]>>a1[2];
	cin>>s[0]>>s[1]>>s1[0]>>s1[1]>>s1[2];
	if(a[0]==s[0]&&a[1]==s[1]){
		cout<<"1";
		if(a1[0]==s1[0]&&a1[1]==s1[1]){
			cout<<"1";
			if(a1[2]<='C'&&s1[2]<='C'){
				cout<<"1";
				if(abs(a1[2]-s1[2])==1){
					cout<<"1";
				}
				else{
					cout<<"0";
				}
			}
			else if(a1[2]>='D'&&s1[2]>='D'){
				cout<<"1";
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
	return 0; 
}
//02 01A 02 01B
