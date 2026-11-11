#include<bits/stdc++.h>
long long n,cnt=0;
long long m,a[500005]={0};
long long c[500005][500005]={0};

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    std::cin.tie(0);

    std::cin>>n>>m;
    for(long long i=1;i<=n;i++)std::cin>>a[i];
    for(long long i=1;i<=n;i++){
        for(long long j=1;j<=n;j++){
            c[i][j]=a[i]-a[j];
        }
    }
    for(long long i=1;i<=n;i++){
        long long mod=0,ct=0;
        for(long long j=1;j<=n;j++){
            if(c[i][j]>0&&mod<m){
                mod+=c[i][j];
                ct++;
            }
        }
        if(ct>=cnt)cnt=ct;
    }
    std::cout<<cnt;
    return 0;
}
