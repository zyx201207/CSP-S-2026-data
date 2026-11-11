#include<bits/stdc++.h>
using namespace std;
string chx1,chx2,zw1,zw2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>chx1>>zw1;
	cin>>chx2>>zw2;
	string s_="0000";
	if(chx1==chx2){
		s_[0]='1';
		if(zw1[0]==zw2[0]&&zw1[1]==zw2[1]){
	    	s_[1]='1';
	    	vector<char>vv_;
	    	vv_.push_back(zw1[2]);
	    	vv_.push_back(zw2[2]);
	    	sort(vv_.begin(),vv_.end());
	    	if((vv_[0]=='A'&&vv_[1]=='B')||(vv_[0]=='A'&&vv_[1]=='C')||(vv_[0]=='B'&&vv_[1]=='C')||(vv_[0]=='D'&&vv_[1]=='F')){
	    		s_[2]='1';
	    		if((vv_[0]=='A'&&vv_[1]=='B')||(vv_[0]=='B'&&vv_[1]=='C')||(vv_[0]=='D'&&vv_[1]=='F')){
	    			s_[3]='1';
				}
			}
	    }
	}
	cout<<s_;
	
	return 0;
} 
