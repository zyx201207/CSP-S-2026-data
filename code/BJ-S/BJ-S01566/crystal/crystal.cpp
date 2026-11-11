#include<iostream>
#include<algorithm>
using namespace std;


const int N=5e5+10;
const int M=2e18;
long long f[N]={0};
long long cf[N]={0};

long long n,m;

bool check(long long x){

    long long need=M;
    for(long long  i=x;i<=n;i++){
        need=min(need,x*f[i]-(cf[i]-cf[i-x]));
        if(need<=m){
                //cout<<x*f[i]-(cf[i]-cf[i-x])<<" ";
            return true;
        }
    }
    return false;
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin>>n>>m;
    long long l=1,mid;
    long long r=n;

    for(long long  i=1;i<=n;i++){
        cin>>f[i];
    }
    sort(f+1,f+n+1);
    for(long long  i=1;i<=n;i++){
        cf[i]=f[i]+cf[i-1];
        //cout<<f[i]<<" "<<cf[i]<<endl;
    }
    while(l+1<r){

        mid=(l+r)/2;
        if(check(mid)==true){

            //cout<<mid<<" ";
            l=mid;
        }
        else{
            r=mid;
        }
    }
    cout<<l;
    return 0;
}
