#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    cin >> n;
    string s;
    for(long long i=1;i<=n;i++){
        long long t;
        char tc;
        cin >> t >> tc;
        for(long long j=1;j<=t;j++){
            s=s+tc;
        }
    }
    string sn=s;
    reverse(sn.begin(),sn.end());
    long long ans=0;
    if(sn==s){
        cout << 0;
        return 0;
    }
    for(long long i=0;i<sn.size();i++){
        if(sn[i]!=s[i]){
            ans++;
            s[i]=s[sn.size()-i-1];
            sn[sn.size()-i-1]=sn[i];
        }
        if(sn==s){
            cout << ans;
            return 0;
        }
    }
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
