/*
CSP-J2 2026 RP++
B 30min 100pts.
*/
#include<bits/stdc++.h>
using namespace std;
const int maxN=2e5+10;
unsigned long long cnt[maxN],ans;
int n;
char chr[maxN];
int main(){
    cin.tie(0),cout.tie(0);
    ios::sync_with_stdio(false);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>cnt[i];
        cin>>chr[i];
    }
    int l=1,r=n;
    while(l<r){
        unsigned long long delta=min(cnt[l],cnt[r]);
        if(chr[l]!=chr[r]){
            ans+=delta;
        }
        cnt[l]-=delta;
        cnt[r]-=delta;
        if(cnt[l]==0) l++;
        if(cnt[r]==0) r--;
    }
    cout<<ans;
    return 0;
}