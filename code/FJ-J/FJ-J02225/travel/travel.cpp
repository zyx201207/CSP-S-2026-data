#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char c1[2],c2[2],s1[3],s2[3];
	cin>>c1[0]>>c1[1];
	for(int i=0;i<3;i++){
		cin>>s1[i];
	}
	cin>>c2[0]>>c2[1];
	for(int i=0;i<3;i++){
		cin>>s2[i];
	}
	
	for(int i=0;i<1;i++){
		if(c1[0]==c2[0]&&c1[1]==c2[1]){
			cout<<1;
		}else{
			cout<<"0000";
			break;
		}
		if(s1[0]==s2[0]||s1[1]==s2[1]){
			cout<<1;
		}else{
			cout<<0;
		}
		if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'&&s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
			cout<<1;
		}else if(s1[2]=='D'||s1[2]=='F'&&s2[2]=='D'||s2[2]=='F'){
			cout<<1;
		}else{
			cout<<0;
		}
		if(s1[2]=='D'||s1[2]=='F'&&s2[2]=='D'||s2[2]=='F'){
			cout<<1;
		}else if(s1[2]+1=='D'){
			cout<<0;
		}else if(s1[2]+1==s2[2]||s1[2]-1==s2[2]){
			cout<<1;
		}else{
			cout<<0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	
	
	
	
	
	
	
	
	return 0;
} 
