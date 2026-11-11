#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	
	if(c1==c2){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}//1
	
	
	bool flag1=0;
	for(int i=0;i<=1;i++)
		if(s1[i]!=s2[i])flag1=1;
	if(!flag1){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}//2
	
	if((s1[2]=='A' || s1[2]=='B'|| s1[2]=='C') && s2[2]<'D'){
		if(abs(s1[2]-s2[2])<=2){
			cout<<1;
		}else{
			cout<<"00";
			return 0;
		}
	}else if((s1[2]=='D' || s1[2]=='F') && s2[2]>='D'){
		cout<<1;
	}else {
		cout<<"00";
		return 0;
	}//3
	
	
	
	if((s1[2]=='A' || s1[2]=='B'|| s1[2]=='C') && s2[2]<'D'){
		if(abs(s1[2]-s2[2])==1)cout<<1;
		else cout<<0;
	}else if((s1[2]=='D' || s1[2]=='F') && s2[2]>='D'){
		cout<<1;
	}else {
		cout<<0;
	}
	//4 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
