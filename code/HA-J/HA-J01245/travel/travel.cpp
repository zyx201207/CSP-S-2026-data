#include<bits/stdc++.h>
using namespace std;
string c,s,cc,ss;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c>>s>>cc>>ss;
    if(c==cc){
    	cout<<"1";
    	if(s[0]==ss[0]&&s[1]==ss[1]){
    		cout<<"1";
    		if((s[2]<='C'&&ss[2]<='C')||(s[2]>='D'&&ss[2]>='D')){
    			cout<<"1";
    			if((s[2]-ss[2]==1)||(ss[2]-s[2]==1)||(s[2]-ss[2]==2)||(ss[2]-s[2]==2)){
    				cout<<"1";
				}else{
					cout<<"0";
				}
			}else{
				cout<<"0"<<"0";
				return 0;
			}
		}else{
			cout<<"0"<<"0"<<"0";
		}
	}else{
		cout<<"0000";
		return 0;
	}

	return 0;
}

