#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2; 
int ans1,ans2,ans3,ans4;
int main(){
	freopen("travel.int","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		ans1=2;
	}else cout<<"0";
	
	if(s1[0]==s2[0] && s1[1]==s2[1] && ans1==2){
		cout<<"1";
		ans2=1;
	}else cout<<"0";
	
	if(((s1[2]=='A' && s2[2]=='B')||(s1[2]=='A'&&s2[2]=='C')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='F'&&s2[2]=='D')||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='C'&&s2[2]=='A')||(s1[2]=='C'&&s2[2]=='B'))&&(ans2==1)){
        	cout<<"1";
			ans3=1;
	}else cout<<"0";
	
	
	if(ans1!=2 && ans2!=1 && ans3!=1)
		cout<<"0";
	else if(((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='F'&&s2[2]=='D')||(s1[2]=='D'&&s2[2]=='F'))&&(ans1==2&&ans2==1&&ans3==1))
	cout<<"1";
	else
	cout<<"0";
	return 0;
} 
