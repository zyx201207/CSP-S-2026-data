#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
ll n,a[N],L,l,r,ans1;
char c[N];
//TODO:long long
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        L+=a[i];
    }
    ll mid=ceil(L*1.0/2),id;
    // for(ll i=1,x=0;i<=n;i++){
    //     x+=a[i];
    //     if(x>=mid){
    //         id=i;
    //         break;
    //     }
    // }
    for(l=1,r=n;l<r;){
        if(a[l]==0){l++;continue;}
        if(a[r]==0){r--;continue;}
        if(c[l]!=c[r]){
            ans1+=min(a[l],a[r]);
        }if(a[l]>=a[r]){
            a[l]-=a[r];
            a[r]=0;
            if(a[l]>0){
                ll i=1,x=0;
                while(a[l]){
                    if(c[r-i]!=c[l])ans1+=min(a[r-i],a[l]);// cout<<min(a[r-i],a[l])<<' '<<a[r-i]<<' '<<a[l]<<'\n';
                    int y=a[l];
                    a[l]=max(x,a[l]-a[r-i]);
                    a[r-i]=max(x,a[r-i]-y);
                    i++;
                    // cout<<ans1<<' '<<a[l]<<'\n';
                }
                // if(c[r-1]!=c[l])ans1+=a[l];
            }
        }else{
            a[r]-=a[l];
            a[l]=0;
            if(a[r]>0){
                ll i=1,x=0;
                while(a[r]){
                    if(c[l+i]!=c[r])ans1+=min(a[l+i],a[r]);
                    int y=a[r];
                    a[r]=max(x,a[r]-a[l+i]);
                    a[l+i]=max(x,a[l+i]-y);
                    i++;
                }
            }
        }l++,r--;
        // cout<<ans1<<'\n';
    }
    // cout<<a[r];
    cout<<ans1<<'\n';
    return 0;
}