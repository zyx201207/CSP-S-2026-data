#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	cout<<1;
	for(int i=0;i<s1.size()-1;i++){
		if(s1[i]!=s2[i]){
			cout<<"000";
			return 0;
		}
	}
	cout<<1;
	char ss=s1[s1.size()-1],sss=s2[s2.size()-1];
	if(ss<='C'&&sss<='C'||ss>'C'&&sss>'C'){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	if(ss>sss)swap(ss,sss);
	if(sss==ss+1){
		cout<<1;
	}else {
		cout<<0;
	}
	return 0;
} 
