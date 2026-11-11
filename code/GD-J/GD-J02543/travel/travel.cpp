#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	
	string ans;
	if(c1==c2)ans+='1';
	else ans+='0';
	string f="",s="";
	char w1,w2;
	for(int i=0;i<2;i++){
		f+=s1[i];
		s+=s2[i];
	}
	w1=s1[2];w2=s2[2];
	if(f==s&&ans[0]=='1')ans+='1';
	else ans+='0';
	
	if(w1>='A'&&w1<='C'&&(w2=='D'||w2=='F'))ans+='0';
	else if(w2>='A'&&w2<='C'&&(w1=='D'||w1=='F'))ans+='0';
	else if(ans[1]=='0')ans+='0';
	else ans+='1';
	
	if(w1=='C'&&w2=='D'||w2=='C'&&w1=='D')ans+='0';
	else if((abs(w1-w2)==1)&&ans[2]=='1')ans+='1';
	else ans+='0';
	cout<<ans;
	return 0;
} 
