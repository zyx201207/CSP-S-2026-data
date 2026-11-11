#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int a[10]={1,1,1,0,0,0};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	if(a[s1[2]-'A']==a[s2[2]-'A']){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	if(a[s1[2]-'A']==0){
		cout<<1;
	}else if(abs((s1[2]-'A')-(s2[2]-'A'))==1){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;                        
}
