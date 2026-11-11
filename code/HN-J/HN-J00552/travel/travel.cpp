#include<bits/stdc++.h>
using namespace std;
bool u(string a,string b){
	for(int i=0;i<2;i++){
		if(a[i]!=b[i])return 1;
	}
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	if(u(s1,s2)){
		cout<<"1000";
		return 0;
	}
	if((s1[2]=='a'||s1[2]=='b'||s1[2]=='c')&&(s2[2]=='d'||s2[2]=='f')){
		cout<<"1100";
		return 0;
	}
	if((s2[2]=='a'||s2[2]=='b'||s2[2]=='c')&&(s1[2]=='d'||s1[2]=='f')){
		cout<<"1100";
		return 0;
	}
	if(!(s1[2]+1==s2[2]||s1[2]-1==s2[2])){
		cout<<"1110";
		return 0;
	}
	cout<<"1111";
	return 0;
}  
