#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int maxn=0;
bool v[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxn=max(maxn,a[i]);
    }
    if(m==n){
        int ans=a[1]&a[2];
        for(int i=3;i<=n;i++){
            ans=ans&a[i];
        }
        cout<<ans;
        return 0;
    }
    if(m==1){
        cout<<maxn;
        return 0;
    }
    int x,y;
    int ans=0;
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){

                if(ans<(a[i]&a[j])) {
                    x=i;
                    y=j;
                }
                ans=max(ans,a[i]&a[j]);
            }
        }
    if(m==2){
        cout<<ans;
        return 0;
    }
    v[x]=v[y]=1;
    for(int i=1;i<=m-2;i++){
        int cnt=-1;
        for(int j=1;j<=n;j++){
            if(v[j]) continue;
            if((ans&a[j])>cnt) x=j;
            cnt=max(ans&a[j],cnt);
        }
        //cout<<x;
        ans=cnt;
        v[x]=1;
    }
    sort(a+1,a+1+n);
    int sum=a[n-m+1];
    ans=max(sum,ans);
    cout<<ans;
    return 0;
}