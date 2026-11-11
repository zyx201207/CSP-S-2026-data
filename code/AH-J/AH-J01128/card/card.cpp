#include<bits/stdc++.h>
using namespace std;
int n,m,a[500001],b[500001],c[500001],ans[500001];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    for(int i=0;i<n;++i){
        memset(b,0,sizeof(b));
        int w=0;
        for(int j=i;j<n;++j){
            if(b[a[j]]!=0){
                for(int k=b[a[j]];k<=w;++k){
                    b[c[k]]=0;
                    c[k]=0;
                }
                w=b[a[j]];
                b[a[j]]=w;
                c[w]=a[j];
            }
        }
        for(int j=1;j<=m;++j){
            if(b[j]){
                ++ans[j];
            }
        }
    }
    for(int i=1;i<=m;++i){
        cout<<ans[i]<<' ';
    }
    return 0;
}
