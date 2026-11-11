#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],maxn,sum1,l=1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    sum1=a[1];
    for(int r=2;r<=n;r++){
        while(a[r]*(r-l)-sum1>m){
            sum1-=a[l];
            l++;
        }
        sum1+=a[r];
        maxn=max(maxn,r-l+1);
    }
    cout<<maxn;
    return 0;
}
