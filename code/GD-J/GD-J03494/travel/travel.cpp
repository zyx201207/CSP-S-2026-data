#include<bits/stdc++.h>
using namespace std;
string a1,a2,s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>a1>>a2>>s1>>s2;
	if(a1==s1){
		if((a2[0]-'0')*10+(a2[1]-'0')==(s2[0]-'0')*10+(s2[1]-'0')){
			if((a2[2]<='C'&&s2[2]<='C')||(a2[2]>='D'&&a2[2]<='F'&&s2[2]>='D'&&s2[2]<='F')){
				if(abs(a2[2]-s2[2])==1||(a2[2]=='D'&&s2[2]=='F')||(s2[2]=='D'&&a2[2]=='F')){
					cout<<"1111";
				}
				else cout<<"1110";
			}
			else cout<<"1100";
		}
		else cout<<"1000";
	}
	else{
		cout<<"0000";
	}
	return 0;
} 
