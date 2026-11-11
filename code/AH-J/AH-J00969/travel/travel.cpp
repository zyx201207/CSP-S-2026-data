#include<bits/stdc++.h>
using namespace std;
string s1,t1,s2,t2;
string ans="0000";
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s1>>t1>>s2>>t2;
    if(s1==s2){
        ans[0]='1';
        if(t1.substr(0,2)==t2.substr(0,2)){
            ans[1]='1';
            if(t1[2]>='A'&&t1[2]<='C'&&t2[2]>='A'&&t2[2]<='C'||t1[2]>='D'&&t1[2]<='F'&&t2[2]>='D'&&t2[2]<='F'){
                ans[2]='1';
                int a=t1[2],b=t2[2];
                if(abs(a-b)==1){
                    ans[3]='1';
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
