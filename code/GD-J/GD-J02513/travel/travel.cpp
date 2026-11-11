#include<bits/stdc++.h>
#define int long long
using namespace std;
string s1,s2,s3,s4;
bool f=1;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3){
		cout<<1;
	}
	else{
		cout<<0;
		f=0;
	}
	if(f&&s2[0]+s2[1]==s4[0]+s4[1]){
		cout<<1;
	}
	else{
		f=0;
		cout<<0;
	}
	string s5;s5+=s2[2],s5+=s4[2];
	sort(s5.begin(),s5.end());
	if(f&&((s5[0]=='A'&&s5[1]=='B')||(s5[0]=='A'&&s5[1]=='C')||(s5[0]=='B'&&s5[1]=='C')||(s5[0]=='D'&&s5[1]=='F'))){
		cout<<1;
	}
	else{
		f=0;
		cout<<0;
	}
	if(f&&((s5[0]=='A'&&s5[1]=='B')||(s5[0]=='B'&&s5[1]=='C')||(s5[0]=='D'&&s5[1]=='F'))){
		cout<<1;
	}
	else{
		f=0;
		cout<<0;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
