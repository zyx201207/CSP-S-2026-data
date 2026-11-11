#include<bits\stdc++.h>
using namespace std;
string c1,s1,c2,s2;
string ans;
bool p=1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		ans+='1';
	}else{
		ans+='0';
		ans+='0';
		ans+='0';
		ans+='0';
		cout<<ans;
		return 0;
	}
	for(int i=0;i<3;i++){
		if(i==1){
		   for(int j=0;j<=1;j++){
		   	   if(s1[j]!=s2[j]){
		   	   	  p=0;
				}
		   }
		   if(p==1){
		   	   ans+='1';
		   }else{
		   	   ans+='0';
		   }	    
		}
		if(i==2){
			if(s1[i]<='C'&&s2[i]<='C'&&p==1){
				ans+='1';
				if(s1[i]=='A'&&s2[i]=='B'||s2[i]=='B'&&s2[i]=='A'||s1[i]=='C'&&s2[i]=='B'||s2[i]=='B'&&s2[i]=='C'){
					ans+='1';
				}else{
					ans+='0';
				}
			}else if('D'<=s1[i]&&'F'>=s1[i]&&'D'<=s2[i]&&'F'>=s2[i]&&p==1){
				ans+='1';
				if(s1[i]=='D'&&s2[i]=='F'||s2[i]=='F'&&s2[i]=='D'){
					ans+='1';
				}else{
					ans+='0';
				}
			}else{
				ans+='0';
				ans+='0';
			}
		}
	}
	cout<<ans;
	return 0;
} 
