#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct node{
    char c;
    ll a;
} arr[200009];
ll len=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ll n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i].a>>arr[i].c;
        len+=arr[i].a;
    }
    ll mid=len/2+1,idx;
    ll r=0,l=0;
    char mid_char;
    ll cnt=0;
    for(int i=1;i<=n;i++){
        r+=arr[i].a;
        if(r>=mid){
            idx=i;
            mid_char=arr[i].c;
            break;
        }
    }
    l=r-arr[idx].a;
    ll ans=0;
    if(arr[1].c==arr[n].c){
        cout<<"0";
        return 0;
    }
    if(len%2==0){
        ll l_qj=mid-l,r_qj=r-mid+1;
        ans=mid-min(l_qj,r_qj);
        cout<<l_qj<<" "<<r_qj<<"\n";
    }
    else{
        ll l_qj=mid-l,r_qj=r-mid;
        ans=mid-min(l_qj,r_qj);
        cout<<l<<" "<<l_qj<<" "<<r_qj<<"\n";
    }
    cout<<ans;
    return 0;
}
