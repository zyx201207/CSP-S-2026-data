#include<bits/stdc++.h>
using namespace std;
int vis[300005],ans[300005];
queue<int> v,b,a;//v shi linshide
//xiamian a[j] dougaiwei front
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i = 0;i<n;i++) {int t;cin>>t;a.push(t);}
    if(n<=5000){
        for(int i = 0;i<n;i++){
            for(int j = i;i<=n;i++){//pai
                int pos = 0,cnt = 0;
                if(!vis[a[j]]) v.push(a[j]),vis[a[j]] = 1;
                else {
                    vis[a[j]] = 0;
                    for(int k = j;k>=i;k--){
                        if(v[k]==v[j]) {pos = k;break;}
                        cnt++;
                    }
                    for(int k = 0;k<pos;k++) b.push(v[k]);
                    for(int k = 0;k<j;j++) v.pop();
                    for(int k = 0;k<n-j+1;k++) b.push(v[k]);
                    memset(v,0,sizeof(v));
                    memset(a,0,sizeof(a));
                    for(int k = i;k<=n-cnt-i+1;k++) a.push(b[k]);
                    memset(b,0,sizeof(b));
                }
            }
            for(int j = 1;j<=m;j++){
                if(vis[m]) ans[m]++;
            }
        }
        for(int i = 1;i<=m;i++)
            if(ans[m])
                cout<<ans[m];
    }
    return 0;
}
