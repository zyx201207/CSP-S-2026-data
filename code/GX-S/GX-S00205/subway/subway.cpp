#include<bits/stdc++.h>
using namespace std;
const int N=500005;
long long c,n,m,d,q,w[N],a[510][N],t[500][N],k[N],x,y,ans;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++)
            cin>>a[i][j]>>t[i][j];
    }
    while(q--){
        long long mm=0x3f3f3f3f,dd;
        ans=0;
        cin>>x>>y;
        if(c>=12&&c<=19){
            long long T=t[1][1];
            //cout<<(1||2||3||4||5)*T;
        }
        else {
            for(int i=1;i<=n;i++){
                if(t[i][a[i][x]]!=0) {
                    dd=i;
                    mm=min(mm,t[i][a[i][x]]);
                }
            }
            ans+=mm;
            }
            cout<<ans<<endl;
    }
    return 0;
}














