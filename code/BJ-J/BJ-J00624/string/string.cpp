#include<bits/stdc++.h>
using namespace std;
int n,l,r;
int a[200005];
char c[200005];
long long ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cin>>c[i];
    }
    l=1,r=n;
    while(l<=r){
        if(l==r) break;
        if(c[l]==c[r]){
            if(a[l]<a[r]){
                a[r]-=a[l];
                l++;
            }
            else if(a[l]==a[r]){
                l++,r--;
            }
            else{
                a[l]-=a[r];
                r--;
            }
        }
        if(c[l]!=c[r]){
            ans+=min(a[l],a[r]);
            if(a[l]<a[r]){
                a[r]-=a[l];
                l++;
            }
            else if(a[l]==a[r]){
                l++,r--;
            }
            else{
                a[l]-=a[r];
                r--;
            }
        }
    }
    cout<<ans;
    return 0;
}