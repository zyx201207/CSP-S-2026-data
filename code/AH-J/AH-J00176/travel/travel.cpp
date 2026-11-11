#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","w",stdin);
	freopen("travel.out","r",stdout);
	long long c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	
	int aa=(int)s1[0]*10+(int)s1[1];
	int bb=(int)s2[0]*10+(int)s2[1];
	if(aa==bb)cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	
	
	int a=s1.size()-1,b=s2.size()-1;
	if((s1[a]=='A'&&s2[b]=='C')||(s1[a]=='C'&&s2[b]=='A')||(s1[a]=='A'&&s2[b]=='B')||(s1[a]=='B'&&s2[b]=='A')||(s1[a]=='B'&&s2[b]=='C')||(s1[a]=='C'&&s2[b]=='B')||(s1[a]=='F'&&s2[b]=='D')||(s1[a]=='D'&&s2[b]=='F'))cout<<1;
	else{
		cout<<"00";
		return 0;
	}
		
	
	
	
	if(abs(s1[a]-s2[b])==1)cout<<1;
	else{
		cout<<0;
	}

	return 0;
}
