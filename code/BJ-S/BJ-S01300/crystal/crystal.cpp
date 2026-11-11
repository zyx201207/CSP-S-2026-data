#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+1;
int n,m,a[N],ans=0;
void fio(const string&str){
#ifndef COMPL
    freopen((str+".in").c_str(),"r",stdin);
    freopen((str+".out").c_str(),"w",stdout);
#endif
}
signed main(){
    fio("crystal");
    cin.tie(0)->ios::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    int lst=1,cnt=0;
    for(int i=1;i<=n;i++){
        cnt+=(i-lst)*(a[i]-a[i-1]);
        while(cnt>m){
            cnt-=(a[i]-a[lst]);
            lst++;
        }
        ans=max(ans,i-lst+1);
    }
    cout<<ans;
    return 0;
}