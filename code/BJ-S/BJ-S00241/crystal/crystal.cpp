#include<bits/stdc++.h>
using namespace std;
const int maxn=5*1e5+10;
long long a[maxn],minu[maxn];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    long long m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    if(n<=2000){
        int maxx=-1;
        for(int i=2;i<=n;i++){//init
            minu[i]=abs(a[i]-a[1]);
        }
        for(int i=1;i<=n;i++){
            /*for(int j=1;j<=n;j++){
                cout<<minu[j]<<" ";
            }
            cout<<endl;*/
            long long m1=m;
            int ans=0;
            int u=i;
            while(u>=1){
                if(minu[u]>m1){
                    break;
                }
                m1-=minu[u];
                u--;
                ans++;
            }
            //cout<<ans<<" of "<<i<<endl;
            maxx=max(maxx,ans);
            long long x=a[i+1]-a[i];
            for(int j=1;j<=i;j++){
                minu[j]+=x;
            }
            for(int j=i+1;j<=n;j++){
                minu[j]-=x;
            }
        }
        cout<<maxx;
        return 0;
    }
    long long s=a[2]-a[1];
    long long t=m/s;
    long long u=1,step=0;
    while(t>=u){
        t-=u;
        u++;
        step++;
    }
    if(step+1>n){
        cout<<n;
    }
    else{
        cout<<step+1;
    }
    return 0;
}