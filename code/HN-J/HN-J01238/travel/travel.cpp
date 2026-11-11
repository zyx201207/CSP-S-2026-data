#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","w",stdin);
	freopen("travel.out","r",stdout);
	long long q;
	char sum[4]={'0','0','0','0'}; 
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		sum[0]='1';
	}else{
		for(int i=0;i<=3;i++){
			cout<<sum[i];
		}
		return 0;

	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		sum[1]='1';
		q=1;
	}else{
		for(int i=0;i<=3;i++){
			cout<<sum[i];
		}
		return 0;
	}
	if(((q==1||s1[2]=='D'||s2[2]=='F')&&(q==1||s2[2]=='D'||s1[2]=='F'))&&((q==1||((s1[2]=='A'&&s1[2]=='B'&&s1[2]=='C')||(s2[2]!='D'&s2[2]!='F')))&&(q==1||((s2[2]=='A'&&s2[2]=='B'&&s2[2]=='C')||(s1[2]!='D'&s1[2]!='F'))))){
		sum[2]='1';
	}else{
		for(int i=0;i<=3;i++){
			cout<<sum[i];
		}
		return 0;
	}
	if((((s1[2]+1)!=s2[2])&&((s2[2]+1)!=s1[2]))&&((s1[2]=='C'||s2[2]=='F')&&(s2[2]=='C'||s1[2]=='F'))){
		
	}else{
		sum[3]='1';
	}
	for(int i=0;i<=3;i++){
		cout<<sum[i];
	}
	return 0;
} 
