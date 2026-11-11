#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1;
    string c2,s2;
    string result="0000";
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        result[0]='1';
        if(s1[0]==s2[0]){
            if(s1[1]==s2[1]){
                result[1]='1';
                if((int(s1[2])==68&&int(s2[2])==67)||
                   (int(s1[2])==67&&int(s2[2])==68)){
                }else{
                    result[2]='1';
                    if(int(s1[2])+1==int(s2[2])||int(s1[2])-11==int(s2[2])){
                        result[3]='1';
                    }
                }
            }
        }
    }
    cout<<result;
    return 0;
}
