#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string S="";
    char c;
    long long n;
    long long a,ans=0;
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>a;
        cin>>c;
        for(long long j=1;j<=a;j++){
            S+=c;
        }
    }
    for(long long i=0;i<S.length()/2;i++){
        if(S[i]!=S[S.length()-1-i]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}