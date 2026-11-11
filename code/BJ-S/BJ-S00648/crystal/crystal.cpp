#include <bits/stdc++.h>
using namespace std;
long long n,m,maxx=0,cnt=0,ans=0;
long long l,r;
long long a[500005]={},s[500005]={};
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i <= n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i = 1;i <= n-1;i++){
        s[i] = a[i+1]-a[i];
    }
    l=1;
    r=0;
    cnt = 1;
    ans = 1;
    for(;r < n-1;){
        if(maxx+cnt*s[r+1]<=m){
            maxx += cnt*s[r+1];
            cnt++;
            ans = max(cnt,ans);
            r++;
        }
        else{
            maxx -= (a[r+1]-a[l]);
            cnt--;
            l++;
        }
        if(r<l){
            r = l-1;
            cnt = 1;
        }
    }
    cout<<ans;
}
