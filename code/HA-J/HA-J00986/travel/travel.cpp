#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,s3,s4;cin>>s1>>s2>>s3>>s4;
	if (s1==s3) cout<<1;
	else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	string c1="",c2="";char s5,s6;
	for (int i=0;i<s2.size();i++){
		if (s2[i]>='0' && s2[i]<='9') c1+=s2[i];
		else s5=s2[i];
	}
	for (int i=0;i<s4.size();i++){
		if (s4[i]>='0' && s4[i]<='9') c2+=s4[i];
		else s6=s4[i];
	}
	if (c1==c2) cout<<1;
	else{
		cout<<0<<0<<0;
		return 0;
	}	
	if (((s5=='A'||s5=='B'||s5=='C' && s6=='A'||s6=='B'||s6=='C') || (s5=='D'||s5=='F' && s6=='D'||s6=='F'))){
		cout<<1;
	}
	else{
		cout<<0<<0;
		return 0;
	}
	if (c1==c2 && (((s5=='D'&&s6=='F') || (s5=='F' && s6=='D'))||abs(int(s5)-int(s6))==1)){
		if (s5=='D' && s6=='C' || s5=='C' && s6=='D') cout<<0;
		else cout<<1;
	}
	else cout<<0;
	return 0;
}
