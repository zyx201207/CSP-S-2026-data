#include<bits/stdc++.h>
using namespace std;
char c1[5],s1[5],c2[5],s2[5];
int ans;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]==c2[0] && c1[1]==c2[1]){
		ans++;
	}
	else{
		cout<<"0000"<<endl;
		return 0;
	}
	if(s1[0]==s2[0] && s1[1]==s2[1]){
		ans++;
	}
	else{
		cout<<"1000"<<endl;
		return 0;
	}
	if(s1[2]=='A' || s1[2]=='B' ||s1[2]=='C'){
		if(s2[2]=='A' || s2[2]=='B' ||s2[2]=='C'){
			ans++;
		}
	}
	else{
		if(s2[2]=='D' || s2[2]=='F'){
			ans++;
		}
	}
	if(((s1[2]=='A'|| s1[2]=='C') && s2[2]=='B') || (s1[2]=='B' && (s2[2]=='C' || s2[2]=='A')) || (s1[2]=='D' && s2[2]=='F') || (s1[2]=='F' && s2[2]=='D')){
		ans++;
	}
	for(int i=1;i<=ans;i++){
		cout<<"1";
	}
	for(int i=1;i<=4-ans;i++){
		cout<<"0";
	}
	return 0;
}
