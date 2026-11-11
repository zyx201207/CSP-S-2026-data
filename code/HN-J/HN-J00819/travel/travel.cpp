#include<bits/stdc++.h>
using namespace std;
int c1,c3;
char s1[7],s2[7];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1;
	for(int i=1;i<=3;i++){
		cin>>s1[i];
	}
	cin>>c3;
	if((c1!=1||c1!=16||c3!=1||c3!=16)&&c1==c3){
		cout<<1;
	}else if((c1==1||c1==16||c3==1||c3==16)&&c1==c3){
		cout<<0;
	}else{
		cout<<"0000";
		return 0;
	}
	for(int i=1;i<=3;i++){
		cin>>s2[i];
	}
	for(int i=1;i<3;i++){
		if(s1[i]==s2[i]&&s1[i]==s2[i]){
			
		}else{
			cout<<"000";
			return 0;
		}
	}
	cout<<1;
	for(int i=3;i<=3;i++){
		if((s1[i]=='C'||s1[i]=='B'||s1[3]=='A')&&(s2[i]=='C'||s2[i]=='B'||s2[i]=='A')||((s1[i]=='D'||s1[i]=='E'))&&(s2[i]=='D'||s2[i]=='E')){
			cout<<1;
		}else{
			cout<<"00";
			return 0;
		}
		if(abs(s1[3]-s2[3])==1){
			cout<<1;
		}else{
			cout<<0;
		}
	}
	return 0;
} 
