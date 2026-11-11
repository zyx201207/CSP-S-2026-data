#include<bits/stdc++.h>
using namespace std;
string s1,s2,a1,a2;
int main(){
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>a1>>a2;
	
	if(a1!=s1){
		cout<<"0000";
		return 0;
	}
	else {
		if(s2[0]!=a2[0]||s2[1]!=a2[1]){
			cout<<"1000";
			return 0;
		}
		else {
			if(s2[2]<'D'&&a2[2]>='D'){
				cout<<"1100";
				return 0;
			}
			else if(a2[2]<'D'&&s2[2]>='D'){
				cout<<"1100";
				return 0;
			}
			else {
				
				if(a2[2]=='A'&&s2[2]=='C'){
					cout<<"1110";
					return 0;
				}
				if(a2[2]=='C'&&s2[2]=='A'){
					cout<<"1110";
					return 0;
				}
				
			}
		}
	}
	cout<<"1111";
	return 0;
}
