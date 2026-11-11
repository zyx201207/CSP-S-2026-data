#include<bits/stdc++.h>
using namespace std;
long long t,cnt=0;
string s,c;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        string ss;
        cin>>ss;
        for(int i=1;i<=n;i++){
            s=s+ss;
        }
    }
    c=s;
    reverse(s.begin(),s.end());
    for(long long i=0;i<=s.size()/2;i++){
        if(s[i]!=c[i]){
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}