#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	if(s1[0]!=s2[0] or s1[1]!=s2[1]){
		cout<<1000;
		return 0;
	}
	if(s1[2]=='A' or s1[2]=='B' or s1[2]=='C'){
		if(s2[2]=='D' or s2[2]=='F'){
			cout<<1100;
			return 0;
		}
	}else if(s1[2]=='D' or s1[2]=='F'){
		if(s2[2]=='A' or s2[2]=='B' or s1[2]=='C'){
			cout<<1100;
			return 0;
		}
	}
	int n1=s1[2]-'A',n2=s2[2]-'A';
	if(abs(n1-n2)==1){
		cout<<1111;
	}else{
		cout<<1110;
	}
	return 0;
}//17min
