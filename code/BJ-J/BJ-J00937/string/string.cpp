#include<iostream>
#include<string>
using namespace std;

//aabbc
//cbbaa
string reverse(string s){
    string q;
    for(int i=s.size()-1;i>=0;i--) q+=s[i];
    return q;
}

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,ans=0;
    cin>> n;
    string s,s1;
    for(int i=1;i<=n;i++){
        int v;
        char c;
        cin>> v >> c;
        while(v--){
                s+=c;
        }
    }
    s1=reverse(s);
    for(int i=0;i<(s.size()/2);i++){
        if(s[i]!=s1[i]) ans++;
    }
    cout<< ans;
    return 0;
}