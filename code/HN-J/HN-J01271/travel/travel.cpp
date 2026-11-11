#include<bits/stdc++.h>
using namespace std;
int sum1,sum2;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>sum1>>s1>>sum2>>s2;
	if(sum1==sum2){
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<1;
			if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D')){
				cout<<1;
				int c1=s1[2]-'A',c2=s2[2]-'A';
				if(s1[2]=='F')c1-=1;
				if(s2[2]=='F')c2-=1;
				if(c2-c1==1||c1-c2==1)cout<<1;
				else cout<<0;
			}else cout<<"00"; 
		}else cout<<"000";
	}else cout<<"0000";
	
	return 0;
} 
