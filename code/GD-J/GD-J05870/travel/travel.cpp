#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int s,ss;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>c1>>s1>>c2>>s2;
	
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	if(s1[0]!=s2[0]||s1[1]!=s2[1]){
		cout<<"1000";
		return 0;
	}
	
	s=s1[2]-'A',ss=s2[2]-'A';
	
	if(max(s,ss)>2&&min(s,ss)<3){
		cout<<"1100";
		return 0;
	}
	if(abs(s-ss)!=1&&max(s,ss)!=5){
		cout<<"1110";
		return 0;
	}
	
	cout<<"1111";
	return 0;
}
