#include<bits/stdc++.h>
using namespace std;
long long n,cnt;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(long long i=0;i<n;i++){
        long long a;
        char c;
        cin>>a>>c;
        for(long long j=0;j<a;j++){
            s+=c;
        }
    }
    if(n==1){
        cout<<0;
        return 0;
    }
    const long long k=s.size();
    if(n==2){
        if(s[0]==s[k-1]){
            cout<<0;
            return 0;
        }
    }
    bool fg=1;
    for(long long i=0,j=k-1;i<j;i++,j--){
        if(s[i]!=s[j]){
            fg=0;
            cnt++;
        }
    }
    if(fg){
        cout<<0;
        return 0;
    }
    else{
        cout<<cnt;
        return 0;
    }
    return 0;
}