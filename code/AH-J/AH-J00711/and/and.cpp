#include<bits/stdc++.h>
int n,m,a[101000];
int ans;
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(m==1){
        cout<<a[n];
        return 0;
    }
    ans=-1;
    if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j) continue;
                ans=max(ans,a[i]&a[j]);
            }
        }
        cout<<ans;
        return 0;
    }
    int x=a[n];
    int c=n-m;
    for(int i=n-1;i>c;i--){
        x=(x&a[i]);
    }
    int y=a[n];
    for(int i=1;i<m;i++){
        y=(y&a[i]);
    }
    cout<<max(x,y);
    return 0;
}
