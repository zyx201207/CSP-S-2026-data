#include<bits/stdc++.h>
using namespace std;
string s;
long long cnt=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        long long a;
        char b;
        cin>>a>>b;
        for(long long j=0;j<a;j++){
            s+=b;
        }
    }
    for(long long i=0;i<(s.size()+1)/2;i++){
        if(s[i]!=s[s.length()-1-i]) cnt++;
    }
    cout<<cnt;
    return 0;
}
