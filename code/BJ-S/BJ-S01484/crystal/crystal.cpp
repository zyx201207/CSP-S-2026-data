#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int n,cnt[N];
long long m,a[N],d,ans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    bool fA=0,fB=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cnt[a[i]]++;
        if(a[i]!=i)fA=1;
        if(i>2){
            d=a[2]-a[1];
            if(a[i]-a[i-1]!=d)fB=1;
        }
    }
    if(fA==0){
        long long i=0;
        while(m>=0){
            ans++;
            i++;
            m-=i;
        }
        cout<<ans;
        return 0;
    }
    if(fB==0){
        long long i=a[1];
        while(m>=0){
            ans++;
            i+=d;
            m-=i;
        }
        cout<<ans+1;
        return 0;
    }
    sort(a+1,a+n+1);
    for(int i=a[2];i<=a[n];i++){
        long long sum=0,cnt=0,st=1;
        while(i-a[st]>m)st++;
        for(int j=st;j<=n;j++){
            if(i>=a[j]){
                sum+=i-a[j];
                cnt++;
                ans=max(ans,cnt);
            }else break;
            if(sum==m)break;
        }
    }
    cout<<ans;
    return 0;
}
