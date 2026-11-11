#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool check(){
	if(s1[2]=='D'){
		if(s2[2]=='F') return 1;
		return 0;
	}else{
		if(s2[2]=='B'||s2[2]=='C') return 1;
		return 0;
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(s1>s2){
		string s3=s1;
		s1=s2,s2=s3;
	}
	cout<<(c1==c2)<<((c1==c2)&&(s1[0]==s2[0])&&(s1[1]==s2[1]))<<((c1==c2)&&(s1[0]==s2[0])&&(s1[1]==s2[1])&&check())<<((c1==c2)&&(s1[0]==s2[0])&&(s1[1]==s2[1])&&(s2[2]==(s1[2]+1))&&(s2[2]!='D'));
	return 0;
}

