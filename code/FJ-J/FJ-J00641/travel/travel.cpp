#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>s1>>s2;
	if(c1!=s1){
		cout<<"0000";
	}else{
		cout<<"1";
		long long flag=0;
		if(c2[0]==s2[0]){
			flag++;
		}
		if(c2[1]==s2[1]){
			flag++;
		}
		if(flag==2){
			cout<<"1";
		}else{
			cout<<"000";
			return 0;
		}
		long long f=0;
		if((c2[2]=='A'||c2[2]=='B'||c2[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')){
			cout<<"1";
			f=1;
		}else if((c2[2]=='D'||c2[2]=='F')&&(s2[2]=='D'||s2[2]=='F')){
			cout<<"1";
			f=1;
		}else{
			cout<<"00";
			return 0;
		}
		if(abs(s2[2]-c2[2])==1&&f==1){
			cout<<"1";
		}else{
			cout<<"0";
			return 0;
		}
	}
	return 0;
}
