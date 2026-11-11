#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010];
int d[500010];
int w[500010];
int ans[500010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int c=1;c<=n;c++){
        for(int i=1;i<=n;i++){
            d[i]=0;
            w[i]=0;
            //cout<<d[i]<<' '<<w[i]<<endl;
        }
        for(int i=c;i<=n;i++){
            if(d[a[i]]==0){
                d[a[i]]++;
                w[a[i]]=i;
            }
            else if(d[a[i]]==1){
                for(int j=w[a[i]];j<=i-1;j++){
                    d[a[j]]=0;
                }
                d[a[i]]++;
                w[a[i]]=i;
            }
        }
        for(int i=c;i<=n;i++){
            if(d[a[i]]==1&&i==w[a[i]])ans[a[i]]++;
            //cout<<i<<' '<<ans[a[i]]<<' '<<a[i]<<' '<<d[a[i]]<<endl;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}
