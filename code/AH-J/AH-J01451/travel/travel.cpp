#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int sum1=0,sum2=0,sum3=0;sum4=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=1;i<=4;i++) cin>>s1[i];
	for(int i=1;i<=4;i++) cin>>s2[i];
	for(int i=1;i<=4;i++) cin>>s3[i];
	for(int i=1;i<=4;i++) cin>>s4[i];
	for(int i=1;i<=4;i++){
		if(s1[i]==s3[i]){
			sum1=1;
		}
		else if(s1[i]!=s3[i]){
			sum1=0;
		}
		else if(s2[1]==s4[1] and s2[2]==s4[2]){
		sum2=1;
		}
		else if(s2[2]!=s4[2]){
		sum2=0;
		}
		else if(s2[3]=='F' and s[4]=='D'||s2[3]=='D' and s[4]=='F'||s2[3]=='A' and s[4]=='B'||s2[3]=='B' and s[4]=='A'||s2[3]=='B' and s[4]=='C'||s2[3]=='C' and s[4]=='B'){
		sum3=1;
		sum4=1;
		}    
		else {
		sum3=0;  
		sum4=0;     
		}      
	}
	cout<<sum1<<sum2<<sum3<<sum4;
	return 0;
}
