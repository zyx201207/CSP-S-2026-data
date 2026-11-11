#include<bits/stdc++.h>
using namespace std;
struct NODE{
    long long a,b[31];
}t[200005];
long long n,m,maxb=-1,ans;
long long g[200005];
long long pow2[31]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824};
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>t[i].a;
        long long s=t[i].a;
        for(int j=30;j>=0;j--){
            if((s/pow2[j])>0){
                s%=pow2[j];
                t[i].b[j]=1;
                if(j>maxb){
                    maxb=j;
                }
            }
        }
    }
    for(int i=maxb;i>=0;i--){
        long long sum=0;
        for(int j=1;j<=n;j++){
            if(t[j].b[i]==1&&g[j]==0){
                sum++;
            }
        }
        if(sum<m){
            continue;
        }else{
            ans+=pow2[i];
            for(int j=1;j<=n;j++){
                if(t[j].b[i]!=1){
                    g[j]=1;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
