#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long mx=-0x3f3f3f3f3f3f3f3f;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    if(m>100000000){
        for(long long i=1;i<=n;i++){
            long long x;
            cin>>x;
            a[i]=a[i-1]+x;
        }
        long long l=1,r=n;
        while(l<=r){
            long long mid=(l+r)>>1;
            if(a[mid]>m){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        cout<<l;
    }
    else{
        for(long long i=1;i<=n;i++){
            cin>>a[i];
        }
        sort(a+1,a+n+1);
        for(long long i=a[1];i<=a[n];i++){
            long long sum=0,cnt=0;
            for(long long j=1;j<=n;j++){
                if(a[j]<=i&&sum+i-a[j]<=m){
                    sum+=i-a[j];
                    cnt++;
                }
                if(a[j]>m||sum>m){
                    continue;
                }

            }
            mx=max(mx,cnt);
        }
        cout<<mx;
    }

    return 0;
}
