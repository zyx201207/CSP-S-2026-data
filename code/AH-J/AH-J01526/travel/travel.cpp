#include<bits/stdc++.h>
using namespace std;
string c1,c2;
char s1[5],s2[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1;
	for(int i=1;i<=3;i++){
		cin>>s1[i];
	}
	cin>>c2;
	for(int i=1;i<=3;i++){
		cin>>s2[i];
	}
	if(c1!=c2){
		cout<<"0000\n";
		return 0;
	}
	cout<<"1";
	if(s1[1]!=s2[1]||s1[2]!=s2[2]){
		cout<<"000\n";
		return 0;
	}
	cout<<"1";
	if('D'<=s1[3]&&s1[3]<='F'&&'D'<=s2[3]&&s2[3]<='F'){
		cout<<"11\n";
		return 0;
	}
	else if('A'<=s1[3]&&s1[3]<='C'&&'A'<=s2[3]&&s2[3]<='C'){
		cout<<"1";
		if(s1[3]-s2[3]==1||s1[3]-s2[3]==-1){
			cout<<"1\n";
			return 0;
		}
		else{
			cout<<"0\n";
			return 0;
		}
	}
	else{
		cout<<"00\n";
		return 0;
	}
	return 0;
}
