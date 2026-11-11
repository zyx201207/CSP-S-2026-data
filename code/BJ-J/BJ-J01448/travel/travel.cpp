#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1;
    string s1;
    string c2;
    string s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<1;
    }else{
        cout<<0;
        cout<<0;
        cout<<0;
        cout<<0;
        return 0;
    }
    int cnt=0;
    for(int i=0;i<2;i++){
        if(s1[i]==s2[i]){
            cnt++;
        }
    }
    if(cnt==2){
        cout<<1;
        if('A'<=s1[2]&&s1[2]<='C'&&'A'<=s2[2]&&s2[2]<='C'){
            cout<<1;
        }else if('D'<=s1[2]&&s1[2]<='F'&&'D'<=s2[2]&&s2[2]<='F'){
            cout<<1;
        }else{
            cout<<0;
            cout<<0;
            return 0;
        }
    }else{
        cout<<0;
        cout<<0;
        cout<<0;
        return 0;
    }
    if(s1[2]==s2[2]+1||s1[2]==s2[2]-1){
        cout<<1;
    }else{
        cout<<0;
    }
    return 0;
}
