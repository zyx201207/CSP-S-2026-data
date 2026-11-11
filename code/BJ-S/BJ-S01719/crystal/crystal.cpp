#include <bits/stdc++.h>
using namespace std;
const int N=1e5*5+10;
long long k;
long long a[N];
long long n,m;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long cnt=1;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(n<=100){
        for(int i=n;i>=1;i--){
                long long k=m;
                long long cnt1=1;
            for(int j=i-1;j>=1;j--){
                if(a[i]-a[j]<=k){
                    cnt1++;
                    k-=(a[i]-a[j]);
                    //cout<<k<<endl;
                }
            }cnt=max(cnt,cnt1);
        }cout<<cnt;
    }else{
        long long c=a[2]-a[1];
        for(long long i=1;i<=n;i++){
            if(m>=i*c){
                //cout<<m<<endl;
                cnt++;
                m=m-i*c;
            }else{
                break;
            }
        }
        cout<<cnt;
    }
    return 0;
}
