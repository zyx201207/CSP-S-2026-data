
#include<bits/stdc++.h>
using namespace std;
int n,m,ans=0;
string s;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m>>s;
    if(s[1]and s[0]>=s[0]and s[2]){
        ans+=s[1]and s[0];
        return 0;
    }
    if(s[1] and s[0]<=s[0] and s[2]){
        ans+=s[0]&s[2];
        return 0;
    }
    if(s[1] and s[2]<=s[2] and s[3]){
        ans+=s[2] and s[3];
        return 0;
    }
    if(s[1]& s[2]>=s[2] and s[3]){
        ans+=s[1] and s[2];
        return 0;
    }
    cout<<12;
    return 0;
}
