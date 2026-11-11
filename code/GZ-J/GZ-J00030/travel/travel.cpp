//GZ-J00030 华东师范大学附属贵阳学校 张歆昀 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	freopen("r","travel.in",stdin);
	freopen("w","travel.out",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<1;
			if(s1[2]=='A'&&(s2[2]=='B'||s2[2]=='C')){
				cout<<1;
			}
			else if(s1[2]=='B'&&(s2[2]=='A'||s2[2]=='C')){
				cout<<1;
			}
			else if(s1[2]=='C'&&(s2[2]=='A'||s2[2]=='B')){
				cout<<1;
			}
			else if(s1[2]=='D'&&s2[2]=='F'){
				cout<<1;
			}
			else if(s1[2]=='F'&&s2[2]=='D'){
				cout<<1;
			}
			else{
				cout<<"00";
				return 0;
			}
			if(s1[2]=='A'&&s2[2]=='B'){
				cout<<1;
			}
			else if(s1[2]=='B'&&(s2[2]=='A'||s2[2]=='C')){
				cout<<1;
			}
			else if(s1[2]=='C'&&s2[2]=='B'){
				cout<<1;
			}
			else if(s1[2]=='D'&&s2[2]=='F'){
				cout<<1;
			}
			else if(s1[2]=='F'&&s2[2]=='D'){
				cout<<1;
			}
			else{
				cout<<'0';
			}
		}
		else{
			cout<<"000";
			return 0;
		}
	}
	else{
		cout<<"0000";
		return 0;
	}
	return 0;
}
