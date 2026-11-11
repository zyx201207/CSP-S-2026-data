#include<iostream>
int c,t;
long long n,d,x[2000005];

bool every(long long i,long long j){
    bool flag=1;
    for(int k=i+1;k<=j;k++){
        if(x[k]-x[k-1]>d)flag=0;
    }
    return flag;
}
long long migrate(long long n,long long d){
    long long cnt=0;
    for(long long i=1;i<=n;i++){
        for(long long j=i+2;j<=n;j++){
            if(x[j]-x[i]>d&&x[i+1]-x[i]<=d&&x[i+1]-x[i]>=-d){
                int n=(x[j]-x[i])%d;
                int m=(x[j]-x[i]-n)/d;
                if(m+1==2&&every(i,j))cnt++;
            }
        }
    }
    return cnt;
}

int main(){
    std::cin.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    std::cin>>c>>t;
    for(int i=1;i<=t;i++){
        std::cin>>n>>d;
        for(int j=1;j<=n;j++)std::cin>>x[j];
        std::cout<<migrate(n,d)<<std::endl;
    }
}
