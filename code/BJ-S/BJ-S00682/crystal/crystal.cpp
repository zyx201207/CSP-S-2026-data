#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long

ll n,m,a[500005],ans,b[500005];
ll f(int l,int r){
    return (r-l+1)*a[r]-(b[r]-b[l-1]);
}

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)b[i]=b[i-1]+a[i];
    for(int i=1;i<=n;i++){
        int l=1,r=i,mid;
        while(l<r){
            mid=(l+r)>>1;
            if(f(mid,i)>m)
                l=mid+1;
            else r=mid;
        }
        ans=max((int)ans,i-r+1);
    }
    cout<<ans;

    return 0;
}
//g++ crystal.cpp -o crystal -std=c++14 -Wall