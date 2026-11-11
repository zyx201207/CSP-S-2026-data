//GZ-J00079 贵阳市新世界学校 李冠儒
#include<bits/stdc++.h>
using namespace std;
#define ll long long
void zf(){
    ll n,m;
    cin>>n>>m;
    vector<ll>a(n);
    vector<ll>ans(m+1,0);
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++){
        ll cnt=1;
        vector<ll>d(m+1,0);
        for(int j=i;j<n;j++){
            if(d[a[j]]){
                for(int k=1;k<=m;k++){
                    if(d[a[j]]<d[k]){
                        d[k]=0;
                    }
                }
            }
            d[a[j]]=cnt;
            cnt++;
        }
        for(int k=1;k<=m;k++){
            if(d[k])ans[k]++;
        }
    }
    for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie();cout.tie();
    int t=1;
    //cin>>t;
    while(t--)zf();
    return 0;
}
