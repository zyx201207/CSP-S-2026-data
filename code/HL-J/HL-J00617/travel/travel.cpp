#include<bits/stdc++.h>
using namespace std;
string s;
int ans[10];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    getline(cin,s);
    if(s[0]==s[7] && s[1]==s[8]){
        ans[1]=1;
        if(s[3]==s[10] && s[4]==s[11]){
        	ans[2]=1;
            if((s[5]>='A' && s[5]<='C' && s[12]>='A' && s[12]<='C')||(s[5]=='D' && s[12]=='F')||(s[5]=='F' && s[12]=='D')){
                ans[3]=1;
                if(int(s[5])-int(s[12])==1 || int(s[12])-int(s[5])==1 || (s[5]=='D' && s[12]=='F')||(s[5]=='F' && s[12]=='D')){
                    ans[4]=1;
                }
            }
        }
    }
    for(int i=1;i<=4;i++){
    	cout<<ans[i];
	}
    return 0;
}
