#include<bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2;
string ans={};
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a1>>a2>>b1>>b2;
    if(a1[0]==b1[0]&&a1[1]==b1[1]){
        ans[0]='1';
        if(a2[0]==b2[0]&&a2[1]==b2[1]){
            ans[1]='1';
            if(('A'<=a2[2]&&a2[2]<='C'&&'A'<=b2[2]&&b2[2]<='C')||('D'<=a2[2]&&a2[2]<='F'&&'D'<=b2[2]&&b2[2]<='F')){
                ans[2]='1';
                if(abs(a2[2]-b2[2])==1){
                    ans[3]='1';
                }else{
                    ans[3]='0';
                }
            }else{
                ans[2]='0';
                ans[3]='0';
            }
        }else{
            ans[1]='0';
            ans[2]='0';
            ans[3]='0';
        }
    }else{
        ans[0]='0';
        ans[1]='0';
        ans[2]='0';
        ans[3]='0';
    }
    for(int i=0;i<=3;i++){
        cout<<ans[i];
    }

    return 0;
}