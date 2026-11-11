#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int u,n,cnt;
long long p[N],d;
int s[5005][5005];
long long f[5005][5005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    //cout<<log2(5000)<<endl;
    int T;
    cin>>u>>T;
    while(T--){
        cin>>n>>d;
        //cout<<n<<" "<<d<<endl;
        for(int i=1;i<=n;i++){
            cin>>p[i];
            //cout<<p[i]<<" ";
        }
        long long h=p[2]-p[1];
        long long k=d/h;
        if(k==1ll){
            cout<<0<<endl;
        }
        else{
            long long g=k*2;
            //cout<<g<<endl;
            cout<<max(0ll,n-g+1ll)<<endl;
        }
    }
    return 0;
}
