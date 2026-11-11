#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s;
    long long n,ans=0,o,l,r;
    cin>>n;
    while(n--){
        long long a;
        cin>>a;
        string t;
        cin>>t;
        for(int i=1;i<=a;i++){
            s+=t;
        }
    }
    if(s.size()%2!=0){
        o=ceil(s.size()*1.0/2)-2;
        l=ceil(s.size()*1.0/2)-2;
        r=ceil(s.size()*1.0/2);
    }else{
        o=ceil(s.size()*1.0/2);
        l=ceil(s.size()*1.0/2);
        r=ceil(s.size()*1.0/2)+1;
    }
    while(o+1){
        if(s[l]!=s[r]){
            ans++;
        }
        r++;
        l--;
        o--;
    }
    cout<<ans;
    return 0;
}
