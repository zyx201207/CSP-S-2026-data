#include<iostream>
using namespace std;
string c1[3],s1[3];
string c2[3],s2[3];

int main(){
	freopen("traval.in","r",stdin);
	freopen("traval.out","w",stdout);
	for(int i=1;i<=10;i++){
		cin>>c1[i]>>s2[i]>>c2[i]>>s2[i];
	if(c1[i]==c2[i]){
		cout<<1;
		
		
	}
	else if(c1[i]!=c2[i]){
		cout<<0;
		
	}
	for(int j=1;j<=10;j++){
	
	if(s1[j]==s2[j]){
		cout<<1;
		
	}
		else if(s1[j]!=s2[j]){
		cout<<0;
		
	}}
	
	
}	
	return 0;
}
