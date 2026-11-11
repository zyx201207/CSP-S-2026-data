#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long a[N];
long long sum[N];
int n;
unsigned long long m;
bool check(long long len){
    for(int i=len;i<=n;i++){
        long long nd=a[i]*len;
        int k=i-len+1;
        long long rst=nd-(sum[i]-sum[k-1]);
        if(rst<=m){
            return 1;
        }
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);

    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }

    long long l=1,r=n,mid;
    long long ans=0;
    while(l<=r){
        mid=(l+r)/2;
        if(check(mid)){
            ans=mid;
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    cout<<ans;



    return 0;
}