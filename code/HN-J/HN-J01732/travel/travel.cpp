#include<bits/stdc++.h>

using namespace std;

string s1,s2,c1,c2;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	if(s1[0]!=s2[0]||s2[1]!=s1[1]){
		cout<<"1000";
		return 0;
	}
	int x=s1[2]-'A',y=s2[2]-'A';
	if(((x==1||x==0||x==2)&&(y==3||y==4))||((x==3||x==4)&&(y==0||y==1||y==2))){
		cout<<"1100";
		return 0;
	}
	if(abs(x-y)!=1){
		cout<<"1110";
		return 0;
	}
	cout<<"1111";
	return 0;
}

