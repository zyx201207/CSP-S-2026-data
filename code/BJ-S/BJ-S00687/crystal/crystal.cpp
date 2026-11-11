#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],cha[500010],cnt[500010],ans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cha[i]=a[i]-a[i-1];
    }
    for(int i=1;i<=n;i++){
        if(cha[i]<0){
            cha[i]*=(-1);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            ans+=cha[j];
            if(ans<=m){
                cnt[i]++;
                continue;
            }
        }
        ans=0;
    }
    sort(cnt+1,cnt+1+n);
    cout<<cnt[n];
    return 0;
}
