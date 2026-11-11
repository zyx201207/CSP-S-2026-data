#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crad.in","r",stdin);
    freopen("crad.out","w",stdout);
    long long n,m,a[10005]={0},ans[10005]={0};
    cin>>n>>m;a[0]=-1;
    for(long long i=1;i<=n;i++){cin>>a[i];}
    for(long long i=2;i<=n+1;i++){
        long long zm[10005]={0},ps=0,zl;
        for(long long j=i-1;j<=n;j++){
            zl=-1;
            for(long long k=1;k<=ps;k++){
                if(zm[k]==a[j]){zl=k;break;}
            }
            if(zl==-1){
                ps+=1;
                zm[ps]=a[j];
            }
            else{
                ps=zl;
                zm[ps]=a[j];
            }
        }
        for(long long j=1;j<=ps;j++){
            long long zj=zm[j];
            ans[zj]+=1;
        }
    }
    for(long long i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
