#include<bits/stdc++.h>
using namespace std;
bool cmp(long long x,long long y){
    return x>y;
}
long long n,m,ans;
long long a[214514];
bool flag[214514];
long long pow2[31]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824};
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int start;
    for(int i=30;i>=0;i--){
        long long tmp=0;
        vector<long long> vec;
        for(long long j=1;j<=n;j++){
            if(a[j]&pow2[i]){
                tmp++;
                vec.push_back(j);
            }
        }
        if(tmp>=m){
            ans+=pow2[i];
            for(auto j:vec)flag[j]=1;
            start=i-1;
            break;
        }
    }
    for(int i=start;i>=0;i--){
        long long tmp=0;
        vector<long long> vec;
        for(long long j=1;j<=n;j++){
            if(flag[j]==1){
                if(a[j]&pow2[i]){
                    tmp++;
                }
                else{
                    vec.push_back(j);
                }
            }
        }
        if(tmp>=m){
            ans+=pow2[i];
            for(auto j:vec)flag[j]=0;
        }
    }
    cout<<ans;
    return 0;
}
