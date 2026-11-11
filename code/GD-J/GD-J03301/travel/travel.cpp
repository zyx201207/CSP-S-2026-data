#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool d,f,s;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
	}
	else {
		cout<<"0000";
		return 0;
	}
	
	for(int i=0;i<4;i++){
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			f=1;
			if((s1[2]==s2[2]+1 || s1[2]+1==s2[2] ||s1[2]+2==70||s2[2]+2==70) && (s1[2]+1!=68&&s2[2]+1!=68)){
				d=1;
			}
		}
		if(f){
			if((s1[2]==65&&s2[2]==67)||(s1[2]==65&&s2[2]==66)||(s1[2]==66&&s2[2]==67)||(s1[2]==68&&s2[2]==70)||(s1[2]==70&&s2[2]==68)||(s1[2]==67&&s2[2]==66)||(s1[2]==67&&s2[2]==65)||(s1[2]==66&&s2[2]==65)){
				s=1;
			}
		}
	
	}
	if(f)cout<<1;
	else cout<<0;
	 if(s)cout<<1;
	else cout<<0;
	if(d)cout<<1;
	else cout<<0;
	
	return 0;
	fclose(stdin);
	fclose(stdout);
} 
