#include <bits/stdc++.h>

using namespace std;

int fun(string s){
    if(s[2]>='A'&&s[2]<='C') return 1;
    else return 2;
}

bool fun2(string s1,string s2){
    if(abs(s1[2]-s2[2])==1) return true;
    else return false;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int x1,x2;
    string s1,s2;
    cin>>x1>>s1>>x2>>s2;
    if(x1==x2){
        cout<<1;
    }
    else cout<<0;
    if(x1==x2&&s1[0]==s2[0]&&s1[1]==s2[1]){
            cout<<1;
    }
    else cout<<0;
    if(x1==x2&&s1[0]==s2[0]&&s1[1]==s2[1]&&fun(s1)==fun(s2)){
        cout<<1;
    }
    else cout<<0;
    if(x1==x2&&s1[0]==s2[0]&&s1[1]==s2[1]&&fun(s1)==fun(s2)&&fun2(s1,s2)){
        cout<<1;
    }
    else cout<<0;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
