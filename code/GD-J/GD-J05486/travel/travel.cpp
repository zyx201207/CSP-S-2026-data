#include<bits/stdc++.h>
using namespace std;
//ios::sync_with_stdio(0);
//cin.tie(0),cout.tie(0);
int c1,c2,a[4];
string s1,s2;
int main(){	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2; 
	if(c1==c2){
		a[1]=1;
	}else{
		cout<<"0000";
		return 0; 
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		a[2]=1;
	}else{
		cout<<"1000";
		return 0; 
	}
	bool w1=(s1[2]=='F')||(s1[2]=='D'),w2=(s2[2]=='F')||(s2[2]=='D');
	if((w1==1)&&(w2==1)){
		cout<<"1111";
		return 0; 
	}else if((w1==1)||(w2==1)){
		cout<<"1100";
		return 0; 
	}else if(((s1[2]=='C')||(s1[2]=='A'))&&(w2=(s2[2]=='C')||(s2[2]=='A'))){
		cout<<"1110";
		return 0;
	}else{
		cout<<"1111";
		return 0; 
	}
}
