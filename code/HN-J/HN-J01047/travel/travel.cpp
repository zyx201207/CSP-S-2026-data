//Aceept my code!!
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
string c1,s1,c2,s2;
map<char,ll>mp;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(char i='A';i<='C';i++){
		mp[i]=1;
	}
	for(char i='D';i<='F';i++){
		mp[i]=2;
	}
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	if(mp[s1[2]]==mp[s2[2]]){
		cout<<1;
		if(abs(s1[2]-s2[2])==1){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		cout<<"00";
	}
	return 0;
}
