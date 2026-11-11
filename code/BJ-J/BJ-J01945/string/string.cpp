#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,a[N],ans;
char b[N];
signed main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
ios::sync_with_stdio(0);
cin.tie(0);cout.tie(0);
cin>>n;
for(int i=1;i<=n;i++){
    cin>>a[i];
    cin>>b[i];
}
int l=1,r=n;
while(l<=r){
    if(b[l]==b[r]){
        if(a[l]>=a[r]){
            a[l]-=a[r];
            a[r]=0;
        }
        else{
            a[r]-=a[l];
            a[l]=0;
        }
    }

    else{
        if(a[l]>=a[r]){
            ans+=a[r];
            a[l]-=a[r];
            a[r]=0;
        }
        else{
            ans+=a[l];
            a[r]-=a[l];
            a[l]=0;
        }
    }
    if(a[l]==0){
        l++;
    }
    else if(a[r]==0){
        r--;
    }
}
cout<<ans;
return 0;
}
