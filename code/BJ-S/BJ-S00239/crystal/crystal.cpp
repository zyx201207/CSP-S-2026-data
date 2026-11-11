#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m;
int a[N];
bool check(int l,int mid){
    int sum=0;
    for(int i=l;i<=mid;i++){
        if(a[i]<=a[mid]){
            sum+=a[mid]-a[i];
        }
    }
    return sum<=m;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    int ans=0;
    for(int i=1;i<=n;i++){
        int l=i,r=n,fans=0;
        while(l<=r){
            int mid=(l+r)/2;
            if(check(i,mid)){
                fans=max(fans,mid);
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        ans=max(ans,fans-i+1);
    }
    cout<<ans;
    return 0;
}
