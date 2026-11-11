#include<bits/stdc++.h>
using namespace std;
bool hui(string s){
    int a=0,b=s.size()-1;
    for(int i=0;i<=s.size()/2;i++){
        if(s[a]!=s[b]) return false;
        a++;b--;
    }
    return true;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,a,x1,x2;
    string s,b,c1,c2;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        if(i==0) x1=a;c1=b;
        if(i==1) x2=a;c2=b;
        for(int j=0;j<a;j++) s=s+b;
    }
    if(hui(s)){
        cout<<0;
        return 0;
    }
    if(n==2){
        cout<<min(x1,x2);
        return 0;
    }
    return 0;
}
