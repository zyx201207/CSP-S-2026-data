#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s1,s2,s3,s4;
    cin>>s1>>s2>>s3>>s4;
    if(s1==s3) cout<<1;
    else{
		cout<<"0000";
		return 0;
	}
    string ss=s2.substr(0,2);
    string sss=s4.substr(0,2);
    if(ss==sss) cout<<1;
    else{
		cout<<"000";
		return 0;
	}
	bool pda=0,pdb=0;
    for(int i=0;i<3;i++){
		if(s2[2]==char('A'+i)) pda=1;
		if(s4[2]==char('A'+i)) pdb=1;
	}
	if(pda==pdb&&pda){
		cout<<1;
		if(abs(s2[2]-s4[2])==1) cout<<1;
		else cout<<0;
	}
	else{
		if((s2[2]=='D'&&s4[2]=='F')||(s4[2]=='D'&&s2[2]=='F')){
			cout<<1<<1;
		}
		else{
			cout<<"00";	
	    }
	}
    return 0;
}
