#include<bits/stdc++.h>
using namespace std;
string s[3000101];
long long n,a[3000101],i,p,q,ans,j;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>a[i];
        cin>>s[i];
    }
    p=1;q=n;
    while(p<q){
        if(s[p]!=s[q]){
            ans+=min(a[p],a[q]);
        }
        j=a[p];
        a[p]-=min(j,a[q]);
        a[q]-=min(j,a[q]);
        if(a[p]==0) p++;
        if(a[q]==0) q--;
        if(p==q) break;
    }
    cout<<ans;
    return 0;
}
