#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int flag,a[6]={0,0,0,0,1,1};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;	
	}else{
		cout<<0;
		flag=1;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&!flag){
		cout<<1;	
	}else{
		cout<<0;
		flag=1;
	}
	if(a[s1[2]-'A'+1]==a[s2[2]-'A'+1]&&!flag){
		cout<<1;	
	}else{
		cout<<0;
		flag=1;
	}
	if((s1[2]+1==s2[2]||s1[2]-1==s2[2])&&!flag){
		cout<<1;	
	}else{
		cout<<0;
		flag=1;
	}
	return 0;
}
