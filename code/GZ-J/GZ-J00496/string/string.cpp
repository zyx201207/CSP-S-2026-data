//GZ-J00496 遵义市第十六中学 张旋彬
#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,cnt=0;
    string s;
    cin>>n;
    long long a;
    string sa;
    for(long long i=0;i<n;i++){
        cin>>a>>sa;
        for(long long i=0;i<a;i++){
            s+=sa;
        }
    }
    long long l=0,r=s.length()-1;
    bool yes=true;
    while(l<=r){
        if(s[l]!=s[r]) yes=false;
        l++;
        r--;
    }
    l=0,r=s.size()-1;
    if(yes) cout<<0;
    else{
       while(l<=r){
            if(s[l]!=s[r]){
                s[r]=s[l];
                cnt++;
            }
            l++;
            r--;
        }
        cout<<cnt;
    }
    return 0;
}
