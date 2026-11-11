#include<bits/stdc++.h>
using namespace std;
string s1,s2,n1,n2;
int cnt1=0,cnt2=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>n1>>n2;
	for(int i=0;i<2;i++){
		if(s1[i]==n1[i]){
			cnt1++;
		}
		if(s2[i]==n2[i]){
			cnt2++;
		}
	}
	if(cnt1==2){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	if(cnt2==2){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	if(cnt2==2&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')&&(n2[2]=='A'||n2[2]=='B'||n2[2]=='C')){
		cout<<"1";
	}else if(cnt2==2&&(s2[2]=='D'||s2[2]=='E')&&(n2[2]=='D'||n2[2]=='E')){
		cout<<"1";
	}else{
		cout<<"00";
		return 0;
	}
	if((s2[2]=='A'&&n2[2]=='B')||(s2[2]=='B'&&n2[2]=='C')||(s2[2]=='B'&&n2[2]=='A')||(s2[2]=='C'&&n2[2]=='B')){
		cout<<"1";
	}else{
		cout<<"0";
	}
	return 0;
} 
