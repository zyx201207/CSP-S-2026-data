#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500001],ans;
long long most(){
    long long maxx=-(1LL<<60);
    map<long long,long long> m;
    for(int i=1;i<=n;i++){
        m[a[i]]++;
        maxx=max(maxx,m[a[i]]);
    }
    return maxx;
}
void dfs(long long cnt){
    if(cnt>m){
        return;
    }
    ans=max(ans,most());
    for(int i=1;i<=n;i++){
        a[i]++;
        dfs(cnt+1);
        a[i]--;
    }
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    bool tmp=true;
    int tmp1;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=i){
            tmp=false;
        }
    }
    if(tmp){
        //tmp1=a[2]-a[1];
        long long cnt=0;
        for(long long i=1;i<n;i++){
            for(long long j=1;j<=i;j++){
                a[j]++;
                cnt++;
            }
            if(cnt>m){
                cout<<i-1;
                break;
            }else if(cnt==m){
                cout<<i;
                break;
            }
        }
    }else{
        dfs(0LL);
        cout<<ans;
    }
    return 0;
}
