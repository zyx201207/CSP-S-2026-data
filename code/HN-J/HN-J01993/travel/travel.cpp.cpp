#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in.c","r",stdin);
    freopen("travel.out.c","w",stdout);
    string c1,s1,c2,s2,ans="";
    int w1=0,w2=0;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
    	ans+="1";
    	if(s1[0]*100+s1[1]==s2[0]*100+s2[1]){
			ans+="1";
			if(s1[2]>'C')w1=1;
			if(s2[2]>'C')w1=1;
			if(w1==w2){
				ans+="1";
				if(w1==1||abs(s1[2]-s2[2])==1){
					ans+="1";
				}else{
					ans+="0";
				}
			}else{
				ans+="00";
			}
		}else{
			ans+="000";
		}
	}else{
		ans+="0000";
	}
	cout<<ans;
    return 0;
}
