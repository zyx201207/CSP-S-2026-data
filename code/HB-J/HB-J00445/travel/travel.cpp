#include <bits/stdc++.h>
using namespace std;
string c,s,cr,sr;
string ans[5];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c>>s>>cr>>sr;
    if(c==cr){
		if(s[0]==sr[0]&&s[1]==sr[1]){
			if((s[2]<='C'&&sr[2]<='C')||(s[2]>='D'&&sr[2]>='D')){
				if((sr[2]-s[2]==-1)||(sr[2]-s[2]==1)){
					cout<<"1111";
					}else{
						cout<<"1110";
					}
				}else{
					cout<<"1100";
					return 0;
				}
		}else{
			cout<<"1000";
			return 0;
		}
	}else{
		cout<<"0000";
		return 0;
	}
    return 0;
}
