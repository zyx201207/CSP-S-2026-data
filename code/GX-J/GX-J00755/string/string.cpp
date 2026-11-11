#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,a[N];
char c[N];

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    int l=1,r=n;
    long long ans=0;
    while(l<r){
        if(c[l]!=c[r]){
            ans+=min(a[l],a[r]);
        }
        int mn=min(a[l],a[r]);
        a[l]-=mn,a[r]-=mn;
        if(!a[l]) l++;
        if(!a[r]) r--;
    }
    cout<<ans;
    return 0;
}
//CCF,I want CSP-J 300pts,please! CSP-S 150+pts,please!
