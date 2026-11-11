#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+5;
long long n,a[MAXN],ans,l,r,li,ri;
char c[MAXN];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i]>>c[i];
    }
    r=n-1;
    for(l,r;l<r;){
        if(c[l]!=c[r]){
            ans+=min(a[l],a[r]);
        }
        if(a[l]<a[r]){
            a[r]-=a[l];
            l++;
        }
        else if(a[l]>a[r]){
            a[l]-=a[r];
            r--;
        }
        else{
            l++;
            r--;
        }

    }
    cout<<ans;
    return 0;
}
