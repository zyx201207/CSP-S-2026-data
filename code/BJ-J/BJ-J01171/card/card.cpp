#include <bits/stdc++.h>
using namespace std;
long long a[1000001],ans1,ans2,ans[1000001];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    bool fl=1;
    for(int i=1;i<=n;i++){
        if(a[i]<a[i-1]) fl=0;
    }
    if(fl){
        int sum1,sum2,cnt=0;
        for(long long i=n;i>=1;i--){
            if(cnt==2) break;
            if(ans[a[i]]==0){
                ans[a[i]]=i;
                cnt++;
            }
        }
        for(int i=1;i<=m;i++){
            cout<<ans[i]<<" ";
        }
        return 0;
    }
    bool f1=0,f2=0;
    for(long long i=n;i>=1;i--){
        if(a[i]==1){
            ans1=max(i,ans1);
            f1=1;
        }
        if(a[i]==2){
            ans2=max(i,ans2);
            f2=1;
        }
    }
    cout<<ans1<<" "<<ans2;
    return 0;
}