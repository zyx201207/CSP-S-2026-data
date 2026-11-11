#include<bits/stdc++.h>
using namespace std;
int n,a;
char b;
string s;
bool ishw(string s){
    for(int i=0;i<s.size();i++){
        if(s[i]!=s[s.size()-i-1]){
            return false;
        }
    }
    return true;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>b;
        for(int j=1;j<=a;j++){
            s+=b;
        }
    }
    if(ishw(s)){
        cout<<0;return 0;
    }
    else{
        cout<<s.size()-1;
    }
    return 0;
}
