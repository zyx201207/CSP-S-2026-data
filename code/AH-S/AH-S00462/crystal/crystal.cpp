#include<bits/stdc++.h>
using namespace std;
long long n,i,m,x,a[1000010],j,cnt=1,mn=-10;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    for(i=0;i<n;i++){
        x=m;
        cnt=1;
        for(j=i-1;j>=0;j--){
            if(a[i]-a[j]<=x){
                x=x-a[i]+a[j];
                cnt++;
            }else break;
        }
        mn=max(mn,cnt);
    }
    cout<<mn;
    return 0;
}
