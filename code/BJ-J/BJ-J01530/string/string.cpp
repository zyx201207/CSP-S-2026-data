#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,t,l,r,s,a[200100],ans;
char b[200100];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
        t+=a[i];
    }
    t/=2;
    l=1;
    r=n;
    while(s<t){
        if(l==r){
            break;
        }
        if(b[l]!=b[r]){
            if(a[l]<a[r]){
                ans+=a[l];
                s+=a[l];
                a[r]-=a[l];
                l++;
            }else if(a[l]>a[r]){
                ans+=a[r];
                s+=a[r];
                a[l]-=a[r];
                r--;
            }else{
                ans+=a[l];
                s+=a[l];
                l++;
                r--;
            }
        }else{
            if(a[l]<a[r]){
                s+=a[l];
                a[r]-=a[l];
                l++;
            }else if(a[l]>a[r]){
                s+=a[r];
                a[l]-=a[r];
                r--;
            }else{
                s+=a[l];
                l++;
                r--;
            }
        }
    }
    cout<<ans;
    return 0;
}

