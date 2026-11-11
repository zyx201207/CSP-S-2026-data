#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","w",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	int t1,t2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<'1';
	} 
	else{
		cout<<"0000";
		return 0;
	} 
	for(int i=0;i<=1;i++){
		if(s1[i]!=s2[i]){
			cout<<"000";
			return 0;
		} 
	}
	cout<<'1';
	if((s1[2]=='D'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='D')){
		cout<<"00";
		return 0;
	}
	cout<<'1';
	if((s1[2]=='D'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='D')){
		cout<<'0';
		return 0;
	}
	else if((s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')){
		cout<<'1';
		return 0;
	}
	else if(s1[2]-'A'+1==s2[2]-'A'||s1[2]-'A'-1==s2[2]-'A'){
		cout<<'1';
		return 0;
	}
	cout<<'0';
	fclose(stdin);
	fclose(stdout);
	return 0;
}
