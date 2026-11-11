#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[200005],ans;
char x[200005];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>x[i];
    }
    int l=1,r=n;
    while(l<r){
        if(x[l]!=x[r]){
            if(a[l]<a[r]){
                a[r]-=a[l];
                ans+=a[l];
                l++;
            }else if(a[l]>a[r]){
                a[l]-=a[r];
                ans+=a[r];
                r--;
            }else if(a[l]=a[r]){
                ans+=a[l];
                l++;
                r--;
            }
        }else{
            if(a[l]<a[r]){
                a[r]-=a[l];
                l++;
            }else if(a[l]>a[r]){
                a[l]-=a[r];
                r--;
            }else if(a[l]=a[r]){
                l++;
                r--;
            }
        }

    }
    cout<<ans;
    return 0;
}
