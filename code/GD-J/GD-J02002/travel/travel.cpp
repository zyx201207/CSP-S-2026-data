#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	string c1,s1,c2,s2;
	int a1[1000],a2[1000],ans1,ans2,bian=0,bian1=0;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		bian=0;
	}else{
		cout<<0;
		bian=1;
	}	
	
		if(s1[1]==s2[1]&&s1[0]==s2[0]&&bian==0){
			cout<<1;
			bian=0;
		}else{
			cout<<0;
			bian1=1;
		}
		
		
		
		if((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')&&bian1==0){
			cout<<1;
		}else if((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F')&&bian1==0){
			cout<<1;
		}else{
			cout<<0;
		}
		
		
		
		for(int i=0;i<s1.size();i++){
			if(s1[i]>'0'&&s1[i]<='9'){
				a1[i]=s1[i]-'0';
			}	if(s2[i]>='0'&&s2[i]<='9'){
				a2[i]=s2[i]-'0';
			}
		}
			ans1=a1[0]*10+a1[1];
			ans2=a2[0]*10+a2[1];
			if((s1[2]=='C'&&s2[2]=='D')||(s1[2]=='D'&&s2[2]=='C')){
				cout<<0;
				return 0;
			}
			if(s1[0]=='0'&&s2[0]=='0'){
				if(s1[1]!=s2[1]&&s1[2]!=s2[2]){
					cout<<0;
					return 0;
				}
			}
			if(bian==0&&(s1[2]+'A'-'B'==s2[2]||s1[2]+'B'-'A'==s2[2]||s1[2]==s2[2])&&(ans1+1==ans2||ans1-1==ans2||ans1==ans2)){
				cout<<1;
			}else{
				cout<<0;
			}
		return 0; 
} 
