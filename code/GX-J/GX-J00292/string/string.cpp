#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s="0";
    long long n;
    cin>>n;
    long long L=0;
    for(long long t=1;t<=n;t++){
        long long l_t;
        string s_t;
        cin>>l_t>>s_t;
        L+=l_t;
        for(long long i=1;i<=l_t;i++){
            s+=s_t;
        }
    }
    //cout<<s;//
    long long cnt=0;
    for(long long i=1;i<=L/2;i++){
        if(s[i]!=s[L-i+1]) cnt++;
    }
    cout<<cnt;
    return 0;
}
