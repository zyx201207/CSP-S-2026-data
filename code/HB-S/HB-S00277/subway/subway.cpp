#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q,w[500010],k[510],a[9000],b[9000];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    int e=1;
    for(int i=1;i<=n;i++){
        cin>>k[i];
        int r,t;
        for(int j=1;j<=k[i];j++){
            cin>>r>>t;
            a[e]=r;
            b[e]=t;
            e++;
        }
    }
    for(int i=1;i<=q;i++){
        int l,r,sum=0;
        cin>>l>>r;
        sum+=w[l];
        sum+=w[r];
        int flag=0;
        for(int j=1;j<e;j++){
            if(a[j]==l){
                sum+=b[j];
                flag=1;
                continue;
            }
            if(a[j]==r){
                sum+=b[j];
                break;
            }
            if(flag==1){
                sum+=b[j];
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
