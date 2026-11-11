#include<bits/stdc++.h>
using namespace std;
long long a[500010],n,m;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    int h=0;
    for(long long i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    long long y=1;
    for(long long i=1;i<=n;i++){
        long long o=0,k=0;
        for(long long j=i;j>=1;j--){
            if(o+a[i]-a[j]>m){
                break;
            }
            o+=a[i]-a[j];
            k++;
        }
        if(k>y){
            y=k;
        }
    }
    cout<<y;
    return 0;
}
