#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans;
bool check(int x){
    long long res=0;
    for(int i=1;i<=x;i++){
        res+=a[i];
    }
    for(int i=x+1;i<=n;i++){
        //printf("res::%lld i::%d",res,i);
        if(a[i-1]*x-res<=m){
            //printf("exit check::i::%d\n",i);
            return 1;
        }
        res=res-a[i-x]+a[i];
    }
    return 0;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1,a+1+n);
    long long r=n,l=1;
    while(l<=r){
        long long mid=(r-l)/2+l;
        //printf("enter check::numberofcrystals::%lld\n",mid);
        if(check(mid)){
            l=mid+1;
            ans=mid;
        }
        else{
            r=mid-1;
        }
    }
    cout << ans;
    return 0;
}
