#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n;
int a[N];
char c[N];
int len;
int ans;
int q[N];
int mid;
int l_,l,r_,r;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        len+=a[i];
        q[i]=q[i-1]+a[i];
    }mid=len/2;
    l=1,r=len;
    l_=1,r_=n;
    while(l<=mid&&l_<r_&&l<r){
        if(c[l_]!=c[r_]){
            if(a[r_]>=a[l_]){
                ans+=a[l_];
                l+=a[l_];
                r-=a[l_];
                a[r_]-=a[l_];
                a[l_]=0;
                l_++;
            }else{
                ans+=a[r_];
                l+=a[r_];
                r-=a[r_];
                a[l_]-=a[r_];
                a[r_]=0;
                r_--;
            }
        }else{
            if(a[r_]>=a[l_]){
                l+=a[l_];
                r-=a[l_];
                a[r_]-=a[l_];
                l_++;
            }else{
                l+=a[r_];
                r-=a[r_];
                a[l_]-=a[r_];
                r_--;
            }
        }
    }cout<<ans;
    return 0;
}
