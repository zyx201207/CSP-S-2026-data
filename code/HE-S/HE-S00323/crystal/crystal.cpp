#include<bits/stdc++.h>
using namespace std;
int n;
long long m,mx;
const int N=5e5+10;
int a[N];
long long ans[N],cnt[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        int now=i;
        cnt[i]=m;
        while(now>=1){
            if(cnt[i]-a[i]+a[now]>=0){
                cnt[i]=cnt[i]-a[i]+a[now];
                now--;
                ans[i]++;
            }else{
                break;
            }
        }
    }
    for(int i=1;i<=n;i++){
        mx=max(mx,ans[i]);
    }
    cout<<mx;
}
