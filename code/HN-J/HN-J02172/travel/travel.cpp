#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	bool f=false;
	if(c1.size()!=c2.size()){
		cout<<"0000";
		return 0;
	}
	for(int i=0;i<c1.size();i++){
		if(c1[i]!=c2[i]){
			f=1;
			break;
		}
	}
	if(f==1){
		cout<<"0000";
		return 0;
	}
	int i=0;
	while(1){
		if(s1[i]>='0'&&s1[i]<='9'){
			if(s1[i]!=s2[i]){
				f=1;
				break;
			}
		}else{
			break; 
		}
		i++;
	}
	if(f==1){
		cout<<"1000";
		return 0;
	}
	if(s1[s1.size()-1]=='A'||s1[s1.size()-1]=='B'||s1[s1.size()-1]=='C'){
		if(s2[s2.size()-1]!='A'&&s2[s2.size()-1]!='B'&&s2[s2.size()-1]!='C'){
			f=1;
		}
	}else{
		if(s2[s2.size()-1]=='A'||s2[s2.size()-1]=='B'||s2[s2.size()-1]=='C'){
			f=1;
		}
	}
	if(f==1){
		cout<<"1100";
		return 0;
	}
	if(abs(int(s2[s2.size()-1])-int(s1[s1.size()-1]))!=1){
		f=1;
	}
	if(f==1){
		cout<<"1110";
		return 0;
	}else{
		cout<<"1111";
		return 0;
	}
	return 0;
}
/*
02 01A 02 01B
*/
 
