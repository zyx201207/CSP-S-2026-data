#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)cout<<"1";
	else cout<<"0";
	int f=1,y=0;
	if(s1==s2){
		y=1;
	}
	for(int i=0;i<s1.size()-1;i++){
		if(s1[i]!=s2[i]){cout<<"0";f=0;break;} 	
	}
	if(f==1&&y==0){cout<<"1";}
	else if(y==1)cout<<"0";
	int f1=0;
	if(y==0&&f==1&&((s1[2]<='C'&&s1[2]>='A'&&s2[2]<='C'&&s2[2]>='A')||(s1[2]<='F'&&s1[2]>='D'&&s2[2]<='F'&&s2[2]>='D'))){
		cout<<"1";
		f1=1;
	} 
	else{
		cout<<"0";
	}
	if(y==0&&f1==1&&(s1[2]-1==s2[2]||s1[2]+1==s2[2])){
		cout<<"1";
		return 0;
	}
	cout<<"0";
	return 0;
}
