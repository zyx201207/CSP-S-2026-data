#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n,k,a[200550];
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    long long ma=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-k;j++){
            long long cnt=a[i],i=0;
            for(int q=1;q<=k;q++){
                    if(j+q==i) i=1;
                cnt=cnt&a[j+q+i];
            }
        ma=max(ma,cnt);
        }
    }
    cout<<ma;
    return 0;
}
