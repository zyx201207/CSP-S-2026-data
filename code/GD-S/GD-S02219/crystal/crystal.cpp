#include<bits/stdc++.h>
using namespace std;
long long n,m,a[50000005],az[10000005],cnt;
bool cmp(long long x,long long y){
    return x>y;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    long long h=0,maxn=INT_MAX,l=0,r=0,l1=0;
    bool k=false;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            az[i]+=abs(a[i]-a[j]);
        }
        if(az[i]<maxn){
            h=a[i];
            maxn=az[i];
        }
    }
    for(int i=1;i<=n;i++){
        az[i]=abs(h-a[i]);
    }
    sort(az+1,az+n+1);
    for(int i=1;i<=n;i++){
        if(m-az[i]>=0){
            m-=az[i];
            cnt++;
        }else break;
    }
    cout<<cnt;
    return 0;
}
