#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m,f[N][N],a[N],sumn[N],summ[N],mid=0,minmid=99999;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sumn[i]+=a[i];
    }
    mid=sum[n]/n;
    for(int i=1;i<=n;i++){
            if(a[i]<=0 && a[i]<=mid){
                if(abs(mid+a[i])<minmid)minmid=a[i];
            }
            else if(a[i]<=mid){
                if(abs(mid-a[i])<minmid)minmid=a[i];
            }
            else {
                if(abs(a[i]-mid)<minmid)minmid=a[i];
            }
    }
    for(int i=1;i<=n;i++){
        a[i]-=minmid;
        if(a[i]<=0)summ[N]+=a[i];
    }
    cout<<n;
}
