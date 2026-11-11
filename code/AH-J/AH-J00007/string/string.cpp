#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[200010],ans;
char b[200010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
    ll l=1,r=n;
    while(l<=r){
        if(b[l]==b[r]){
            if(a[l]>=a[r]){
                a[l]=a[l]-a[r];
                a[r]=0;
            }
            else if(a[l]<a[r]){
                a[r]=a[r]-a[l];
                a[l]=0;
            }
            if(!a[l])l++;
            if(!a[r])r--;
        }
        else{
            if(a[l]>=a[r]){
                a[l]=a[l]-a[r];
                ans+=a[r];
                a[r]=0;
            }
            else if(a[l]<a[r]){
                a[r]=a[r]-a[l];
                ans+=a[l];
                a[l]=0;
            }
            if(!a[l])l++;
            if(!a[r])r--;
        }
    }
    cout<<ans;
    return 0;
}
