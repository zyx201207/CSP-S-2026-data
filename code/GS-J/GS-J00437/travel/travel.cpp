#include<bits/stdc++.h>
using namespace std;
string cx1,s1,cx2,s2;
string ans="";
int a[5],b[5];
int flag=0;
bool ce(char a1,char a2){
	if(a1<='C'&&a2<='C'){
		return true;
		
	}
	if(a1>'C'&&a2>'C'){
		return true;
		
	}
	return false;
	
}
bool ling(char a1,char a2){
	int cnt=max(a1,a2)-min(a1,a2);
	if(max(a1,a2)=='D'&&min(a1,a2)=='C'){
		return false;
		
	}
	if(cnt==1){
		return true;
		
	}
	return false;
	
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>cx1>>s1>>cx2>>s2;
	if(cx1==cx2){
		ans+="1";
		flag++;
		
	}
	else{
		ans+="0";
		
	}
	
	
	
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&flag==1){
		ans+="1";
		flag++;
			
	}
	else{
		ans+="0";
	}
	if(flag==2&&ce(s1[2],s2[2])){
		ans+="1";
		flag++;
			
		}
	else{
		ans+="0";
	}	
	if(flag==3&&ling(s1[2],s2[2])){
		ans+="1";
		flag++;
			
		}
	else{
		ans+="0";
	}	
	
	cout<<ans;
	
	
//	s1.substring(0,1);
	return 0;
	
} 
