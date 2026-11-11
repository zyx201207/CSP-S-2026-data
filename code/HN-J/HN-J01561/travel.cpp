#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	int c1,c2;
	bool ans1,ans2,ans3,ans4;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)ans1=1;
	else {
		cout<<"0000";
		return 0;
	}
	int p1=0,p2=0,a1=0,a2=0;
	for(int i=1;i<=s1.size();i++){
		if(s1[i]>='0'&&s1[i]<='9')p1=p1*10+s1[i]-'0';
		else a1+=s1[i]-'A'/2;
	}
	
	for(int i=1;i<=s2.size();i++){
		if(s2[i]>='0'&&s2[i]<='9')p2=p2*10+s2[i]-'0';
		
		else a2+=s2[i]-'A'/2;
	}
	if(a1==6)a1==5;
	if(a2==6)a2==5;
	if(p1==p2)ans2=1;
	else ans2=0;
	
	if(p1==p2&&a1+a2!=7&&abs(a1-a2)<=2)ans3=1;
	else ans3=0;
	
	
	if(p1==p2&&abs(a1-a2)==1&&abs(a1-a2)<=2&&a1+a2!=7)ans4=1;
	else ans4=0;
	
	cout<<ans1<<ans2<<ans3<<ans4;
	
	return 0;
} 

