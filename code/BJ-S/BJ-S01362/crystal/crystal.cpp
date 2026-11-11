#include<bits/stdc++.h>
using namespace std;
long long a[500005], ans;
bool f=1;
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    long long n, m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        f*=(a[i]==i);
    }
    if(f){
        long long cnt=1;
        for(int i=n-1;i>0;i--){
            if(m>=a[n]-a[i]){
                m-=(a[n]-a[i]);
                cnt++;
            }
            else {
                break;
            }
        }
        cout<<cnt;
        return 0;
    }
    f=1;
    for(int i=3;i<=n;i++){
        f*=(a[i]-a[i-1]==a[i-1]-a[i-2]);
    }
    if(f){
        long long cnt=1;
        for(int i=n-1;i>0;i--){
            if(m>=a[n]-a[i]){
                m-=(a[n]-a[i]);
                cnt++;
            }
            else {
                break;
            }
        }
        cout<<cnt;
        return 0;
    }
    sort(a, a+n);
    for(int i=1;i<=n;i++){
        long long cnt=1, x=m;
        for(int j=i-1;j>0;j--){
            if(x>=a[i]-a[j]){
                x-=(a[i]-a[j]);
                cnt++;
            }
            else{

                break;
            }
        }
        ans=max(ans, cnt);
    }
    cout<<ans;
    return 0;
}
