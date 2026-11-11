#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	int t1=(s1[0]-'0')*10+s1[1]-'0',t2=(s2[0]-'0')*10+s2[1]-'0';
	if(t1!=t2){
		cout<<"1000";
		return 0;
	}
	bool f1=0,f2=0;
	if(s1[2]=='D'||s1[2]=='F')f1=true;
	if(s2[2]=='D'||s2[2]=='F')f2=true;
	if(f1!=f2){
		cout<<"1100";
		return 0;
	}
	if(abs(s2[2]-s1[2])!=1&&!(s2[2]=='D'&&s1[2]=='F')&&!(s2[2]=='F'&&s1[2]=='D')){
		cout<<"1110";
		return 0;
	}
	cout<<"1111";
	return 0;
}
