#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
int n;
long long m,a[maxn];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    long long l=a[1],r=a[n],cnt=0,ans=0;
    long long ss=0;
    bool ff=1;
    for(int i=1;i<n;i++){
        if(ss+a[n]-a[i]<=m) ss=ss+a[n]-a[i];
        else {
            ff=0;
            break;
        }
    }
    if(ff&ss<=m){
        cout<<n;
        return 0;
    }
    for(long long mid=a[1];mid<a[n];mid++){
        long long sum=0;
        cnt=0;
        int ll=lower_bound(a+1,a+1+n,mid)-a;
        int rr=upper_bound(a+1,a+1+n,mid)-a;
        sum=rr-ll;
        ll=ll-1;
        if(mid-a[ll]>m){
            continue;
        }
        while(cnt+mid-a[ll]<=m&&ll>=1){
            cnt+=mid-a[ll];
            ll--;
            sum++;
        }
        ans=max(ans,sum);
        if(ans==n-1) break;
    }
    cout<<ans;
    return 0;
}