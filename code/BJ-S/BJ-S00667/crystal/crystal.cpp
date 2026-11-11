#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m;
ll a[500005],cf[500005];
ll tmp=0,cnt=1,maxx = -1e18;
ll l = 1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i <= n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i = 1;i <= n;i++){
        cf[i] = abs(a[i] - a[i-1]);
    }
    for(int i = 2;i <= n;i++){
        tmp += cf[i]*(i-1);
        if(tmp > m){
            maxx = max(maxx,cnt);
            while(tmp >= m && l < i){
                tmp -= a[i] - a[l];
                l++;
                cnt--;
            }
        }
        cnt++;
    }
    cout<<maxx<<endl;
    return 0;
}
