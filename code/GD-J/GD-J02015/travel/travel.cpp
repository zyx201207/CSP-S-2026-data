#include<bits/stdc++.h>
using namespace std;
string c,s,cc,ss;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>cc>>ss;
	if(c!=cc){
		cout<<"0000";
		return 0;
	}else{
		cout<<1;
		string b=" ",bb=" ";
		char u=s[s.size()-1],uu=ss[ss.size()-1];
		for(int i=0;i<s.size()-1;i++){
			b+=s[i],bb+=ss[i];
		}
		if(b!=bb){
			cout<<"000";
			return 0;
		}else{
			cout<<1;
			if(u=='A'||u=='B'||u=='C'){
				if(uu=='A'||uu=='B'||uu=='C'){
					cout<<1;
				}else{
					cout<<"00";
					return 0;
				}
			}else{
				if(uu=='D'||uu=='F'){
					cout<<1;
				}else{
					cout<<"00";
					return 0;
				}
			}
			if((u=='A'&&uu=='B')||(u=='B'&&uu=='C')||(u=='D'&&uu=='F')){
				cout<<1;
			}else if((uu=='A'&&u=='B')||(uu=='B'&&u=='C')||(uu=='D'&&u=='F')){
				cout<<1;
			}else{
				cout<<0;
			}
		}
	}
	return 0;
} 
