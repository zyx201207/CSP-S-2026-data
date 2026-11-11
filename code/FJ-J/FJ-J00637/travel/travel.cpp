#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<c1.size();i++){
		if(c1[i]!=c2[i]){
			cout<<"0000";
			return 0;
		}
	}
	cout<<"1";
	for(int i=0;i<s1.size()-1;i++){
		if(s1[i]!=s2[i]){
			cout<<"000";
			return 0;
		}
	}
	cout<<"1";
	if(s1[2]<='C'&&s2[2]<='C'||(s1[2]>='D'&&s2[2]>='D')){
		cout<<"1";
	}
	else{
		cout<<"00";
		return 0;
	}
	if(s1[2]+0-s2[2]==1||s2[2]+0-s1[2]==1) cout<<"1";
	else cout<<"0";
	return 0;
}
