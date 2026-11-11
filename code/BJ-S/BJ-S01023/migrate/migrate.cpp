#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d;
long long x[2000006];
void solve2(){
    printf("0\n");
}
void solve1(){
    long long gc=x[2]-x[1];

    if(gc>d){
        printf("0\n");
        return;
    }
    long long c=d/gc;
    //cout<<"?"<<gc<<" "<<d<<" "<<c<<" "<<n<<endl;
    printf("%lld\n",max(0ll,n-(c<<1)+1));
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(long long i=1;i<=n;i++){
            cin>>x[i];
        }
        unsigned long long tmp=d+x[1];
        if(tmp<(unsigned long long)x[n]) solve2();
        else solve1();
    }

    return 0;
}
