#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool f;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<'1';
	}else{
		cout<<"0000";
		return 0;
	}
	for(int i=0;i<=1;i++){
		if(s1[i]!=s2[i]){
			f=true;
			break;
		}
	}
	if(f){
		cout<<"000";
		return 0;
	}else{
		cout<<'1';
	}
	if(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C'){
		cout<<'1';
	}else if(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F'){
		cout<<'1';
	}else{
		cout<<"00";
		return 0;
	}
	if(s1[2]+1==s2[2]||s2[2]+1==s1[2]){
		cout<<'1';
	}else{
		cout<<'0';
	}
	return 0;
}
