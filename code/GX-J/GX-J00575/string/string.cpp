#include<bits/stdc++.h>
using namespace std;
string stt;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    cin>>n;
    for(int i=1;i<=n;i++){
        long long t;
        cin>>t;
        char s;
        cin>>s;
        for(int i=1;i<=t;i++){
            stt+=s;
        }
    }
    string st=stt;
    int ans=0;
    reverse(st.begin(),st.end());
    for(int i=0;i<stt.size();i++){
        if(stt[i]!=st[i]) ans++;
    }
    cout<<ans/2;
    return 0;
}
