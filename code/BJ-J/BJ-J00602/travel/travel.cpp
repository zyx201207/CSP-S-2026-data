#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
bool j(char a,char b){
	if(a=='D'&&b!='F') return 0;
	if(b=='D'&&a!='F') return 0;
	if(a=='F'&&b!='D') return 0;
	if(b=='F'&&a!='D') return 0;
	return 1;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
	}
	if(c1==c2){
		cout<<1;
		if(s1[1]==s2[1]){
			cout<<1;
			if(j(s1[2],s2[2])){
				cout<<1;
				if(s1[2]-s2[2]==1||s2[2]-s1[2]==1){
					cout<<1;
				}
				else cout<<0;
			}
			else cout<<"00";
		}
		else
		{
			cout<<"000";
		}
	}
	return 0;
}
