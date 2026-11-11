#include<bits/stdc++.h>
using namespace std;
string c1_,s1_,c2_,s2_;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    
    string ss_="";
    cin>>c1_>>s1_>>c2_>>s2_;
    if(c1_==c2_) {
	    ss_+="1";
	    if(s1_[0]==s2_[0] and s1_[1]==s2_[1]){
	    	ss_+="1"; 
	    	if((s1_[2]>='A' and s2_[2]>='A' and s1_[2]<='C' and s2_[2]<='C') or (s1_[2]>='D' and s2_[2]>='D')){
	    		ss_+="1";
	    		if((s1_[2]>='D' and s2_[2]>='D') or ((s1_[2]=='A' and s2_[2]=='B') or (s1_[2]=='B' and s2_[2]=='C'))){
	    			ss_+="1";
				}else ss_+="0";
			}
			else ss_+="00";
		}
		else ss_+="000";
	}
    else ss_="0000";
    cout<<ss_;
	return 0;
} 
