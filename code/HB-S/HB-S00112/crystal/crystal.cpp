#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N=5e5+10;
int n;
int ans=0;
ll m;
ll a[N];
ll arr[N]={0};
ll sum[N]={0};

bool cmp(int x,int y){
    return x<y;
}

bool check(int mid){

    if(arr[mid]<=m){
        return true;
    }
    else{
        return false;
    }

}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);


    cin>>n>>m;

    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    sort(a+1,a+n+1,cmp);


    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
        arr[i]=a[i]*(i-1)-sum[i-1];
    }


    int l=0,r=n;
    while(l<=r){
        ll mid=(l+r)>>1;
        if(check(mid)){
            l=mid+1;
            ans=mid;
        }
        else{
            r=mid-1;
        }

    }

    cout<<ans;

    return 0;

}
