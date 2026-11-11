#include<bits/stdc++.h>
using namespace std;
long long n,m,a[20010],maxa=0;
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    if(m==n){
        maxa=a[1];
        for(int i=2;i<=n;i++)
            maxa=maxa&a[i];
    }
    else if(m==1)
        for(int i=1;i<=n;i++)
            maxa=max(maxa,a[i]);
    else if(m==2){
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                maxa=max(maxa,(a[i]& a[j]));
            }
        }
    }
    else if(m==n-1){
        maxa=a[1];
        for(int i=1;i<=n;i++){
            if(i==1)maxa=a[2];
            int j=2;
            while(j<=n){
                if(j==i)continue;
                else maxa=maxa&j;
            }
    }
    }
    cout<<maxa;
}
int main(){
    ios::sync_with_stdio(false);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    solve();
    return 0;
    }
