#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,n,m,d,q,x,y,ans=0x3f3f3f3f;
ll w[500005],k[505],a[505][500005],t[505][500005];
bool se(ll s,ll m){
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=k[i];j++){
            if(i!=s&&a[i][j]==m){
                return 1;
            }
        }
    }
    return 0;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(ll i=1;i<=m;i++)cin>>w[i];
    for(ll i=1;i<=n;i++){
        cin>>k[i];
        for(ll j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
        }
    }
    for(ll i=1;i<=q;i++){
        cin>>x>>y;
        queue<int> q1;
        queue<int> q2;
        queue<int> q3;
        for(ll i=1;i<=n;i++)
            for(ll j=1;j<=k[i];j++)
                if(a[i][j]==x){
                    q1.push(i);q2.push(j);q3.push(w[i]);
                }
        while(!q1.empty()){
            ll qq1=q1.front(),qq2=q2.front(),qq3=q3.front();
            if(q2.front()==x){
                q1.push(qq1),q3.push(qq3);
                if(qq2!=k[qq1])q2.push(qq2-1);
            }else{
                for(ll i=1;i<=n&&i!=qq2;i++){
                    se(i,qq3);
                }
                if(qq2==y){
                    ans=min(ans,qq3+w[i]);
                }
            }
            q1.pop(),q2.pop(),q3.pop();
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
