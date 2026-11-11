#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,a[N];
long long ans=0;
char c[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    int l=1,r=n;
    while(l<r){
        if(a[l]<a[r]){
            if(c[l]!=c[r]){
                ans+=a[l];
            }
            a[r]-=a[l];
            a[l]=0;
            l++;
        }
        if(a[l]>a[r]){
            if(c[l]!=c[r]){
                ans+=a[r];
            }
            a[l]-=a[r];
            a[r]=0;
            r--;
        }
        if(a[l]==a[r]){
            if(c[l]!=c[r]){
                ans+=a[l];
            }
            a[l]=a[r]=0;
            l++,r--;
        }
    }
    cout<<ans;
    return 0;
}
