#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string S,s1;
    long long n,a,l;
    long long ans=0;
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>a>>s1;
        for(long long j=1;j<=a;j++){
            S+=s1;
        }
    }
    l=S.size();
    for(long long i=0;i<l/2;i++){
        if(S[i]!=S[l-1]){
            ans++;
        }
    }
    cout<<ans;

    return 0;
}
