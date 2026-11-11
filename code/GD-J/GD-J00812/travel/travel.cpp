#include<bits/stdc++.h>
using namespace std;
long long c1,c2;
string s1,s2,ss1,ss2,sss1,sss2;
long long pan;
long long ans1,ans2,ans3,ans4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) ans1=1;
	else ans1=0;
	
	ss1[0]=s1[0];
	ss1[1]=s1[1];
	ss2[0]=s2[0];
	ss2[1]=s2[1];
	sss1[0]=s1[2];
	sss2[0]=s2[2];
	
	if(ans1==1 and ss1[0]==ss2[0] and ss1[1]==ss2[1]){
		ans2=1;
	}else{
		ans2=0;
	}
	if(ans2==1){
		if(sss1[0]>='D' and sss2[0]>='D'){
			ans3=1;
			pan=1;
		}else if(sss1[0]<'D' and sss2[0]<'D'){
			ans3=1;
		}else{
			ans3=0;
		}
	}else{
		ans3=0;
	}
//	cout<<ss1<<" "<<ss2<<endl;
	if(ans3==1){
		if(pan==1){
			ans4=1;
		}else{
			if(sss1[0]=='A' and sss2[0]=='B') ans4=1;
			if(sss1[0]=='B' and sss2[0]=='A') ans4=1;
			if(sss1[0]=='B' and sss2[0]=='C') ans4=1;
			if(sss1[0]=='C' and sss2[0]=='B') ans4=1;
		}
	}
	cout<<ans1<<ans2<<ans3<<ans4;
} 
