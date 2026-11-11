#include<bits/stdc++.h>
using namespace std;
long long t,n;
string s;
bool che(string x){
    string k="";
    for(long long i=x.size()-1;i>=0;i--){
        k+=x[i];
    }
    if(k==x){
        return true;
    }else{
        return false;
    }
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>t;
    s=" "+s;
    while(t--){
        long long x;
        char c;
        cin>>x>>c;
        n+=x;
        for(long long i=1;i<=x;i++){
            s+=c;
        }
    }
    if(che(s)){
        cout<<0;
        return 0;
    }
    long long ans=0;
    long long l=1,r=n;
    while(l<r){
        if(s[l]!=s[r])
            ans++;
        l++,r--;
    }
    cout<<ans;
    return 0;
}
