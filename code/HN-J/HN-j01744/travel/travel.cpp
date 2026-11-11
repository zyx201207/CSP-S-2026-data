#include <bits/stdc++.h>
using namespace std;
string c,s,cc,ss;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>cc>>ss;
	if(c==cc){
		cout<<"1";
		for(int i=0;i<2;i++){
			if(s[i]!=ss[i]){
				cout<<"000";
				return 0;
			}
		}
		cout<<"1";
		int f1=0,f2=0;
		if(s[2]=='A' || s[2]=='B' || s[2]=='C') f1=1;
		if(ss[2]=='A' || ss[2]=='B' || ss[2]=='C') f2=1;
		if(f1==1 && f2==1){
			if(char(int(s[2])+1)==ss[2] && s[2]!='D' || char(int(ss[2])+1)==s[2]) cout<<"11";
			else cout<<"10";
			return 0;
		}
		else{
			if(c[2]=='D' && cc[2]=='F' || c[2]=='F' && cc[2]=='D'){
				cout<<"11";
				return 0;
			}
			cout<<"00";
		}
		
	}
	else{
		cout<<"0000";
	}
	return 0;
} 
