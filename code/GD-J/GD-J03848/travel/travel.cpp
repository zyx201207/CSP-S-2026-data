#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
void doit(){
	char ma=max(s1[2],s2[2]),mi=min(s1[2],s2[2]);
	int t1=stoi(s1.substr(0,2)),t2=stoi(s2.substr(0,2));
	if(c1!=c2){
		cout<<"0000"; 
		return;
	}
	cout<<"1";
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<"1";
		if(ma=='F'&&mi=='D'||ma<='C') cout<<"1";
		else cout<<"0";
	} 
	else cout<<"00";
	if(ma>='D'&&mi<='C'){
		cout<<"0";
		return;
	}
	if(t1==t2&&ma-mi==1){
		cout<<"1";
		return;
	}
	if(ma==mi&&max(t1,t2)-min(t1,t2)==1){
		cout<<"1";
		return;
	}
	cout<<"0";
	
}
int main(){
	freopen("travel.out","w",stdout);
	freopen("travel.in","r",stdin);
	cin>>c1>>s1>>c2>>s2;
	doit();
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
