#include<bits/stdc++.h>
using namespace std;
bool sh(string s){
    string res="";
    int len=s.size();
    while(len>=0){
        res+=s[len];
        len--;
    }
    if(res==s) return true;
    else return false;

}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    string s="";
    for(int i=1;i<=n;i++){
        int k;
        string c;
        cin>>k>>c;
        for(int j=1;j<=k;i++){
            s+=c;
        }
    }
    if(sh(s)) cout<<0;
    return 0;
}
