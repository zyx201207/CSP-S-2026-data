#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    string x;
    if(c1==c2){
    	x+="1";
    	if(s1[0]==s2[0]&&s1[1]==s2[1]){
    		x+="1";
    		if(s1[2]<='C'&&s2[2]<='C'){
    			x+="1";
    			if(abs(s1[2]-s2[2])==1){
    				x+="1";
				}
				else{
					x+="0";
				}
			}
			else if(s1[2]>='D'&&s2[2]>='D'){
				x+="11";
			}
			else{
				x+="00";
			}
		}
		else{
			x+="000";
		}
	}
	else{
		x+="0000";
	}
	cout<<x;
	return 0;
} 
