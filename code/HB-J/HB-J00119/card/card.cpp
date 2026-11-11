#include <bits/stdc++.h>
using namespace std;
const long long N=5*1e5+2;
const long long M=3*1e5+2;
long long n,m,a[N],ans[M];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }for(long long i=0;i<n;i++){
        long long is[M]={0},pre[N]={0};
        for(long long j=i+1,p=1;j<=n;j++,p++){
            if(!is[a[j]]){
                is[a[j]]=1,pre[a[j]]=p;
            }else{
                for(long long k=pre[a[j]]+1;k<=p;k++){
                    is[a[k]]=0,pre[a[k]]=0;
                }p=pre[a[j]];
            }
        }for(long long k=1;k<=m;k++){
            if(is[k]){
                ans[k]++;
            }
        }
    }for(long long i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}
