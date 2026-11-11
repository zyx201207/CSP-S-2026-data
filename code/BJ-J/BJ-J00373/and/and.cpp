#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200001];
int tmp[200001];
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int res=0;
    for(int i=31;i>=0;i--){
        memset(tmp,0,sizeof(tmp));
        int cnt=0;
        for(int j=1;j<=n;j++){
            if((a[j]>>i)&1){
                tmp[++cnt]=a[j];
            }
        }
        if(cnt>=m){
            res+=(1<<i);
            for(int k=1;k<=cnt;k++){
                a[k]=tmp[k];
            }
            n=cnt;
        }
    }
    cout<<res;
    return 0;
}
