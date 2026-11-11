#include<bits/stdc++.h>

using namespace std;

long long a[500010];

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);cout.tie(nullptr);
    int n;
    long long m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    long long sumcha=0;
    int lp=1;
    int rp=1;
    int maxans=1;
    while((lp<=rp)&&(rp<n)){
        rp++;
        sumcha+=(a[rp]-a[rp-1])*(1LL*((rp-1)-lp+1));
        while((lp<rp)&&(sumcha>m)){
            sumcha-=(a[rp]-a[lp]);
            lp++;
        }
//        cerr<<"debug: "<<lp<<" "<<rp<<endl;
        maxans=max(maxans,(rp-lp+1));
    }
    cout<<maxans<<endl;
    return 0;
}
