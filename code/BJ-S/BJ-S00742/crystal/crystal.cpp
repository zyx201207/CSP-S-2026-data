#include<bits/stdc++.h>
using namespace std;
using lld=long long;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    lld n,m;
    cin>>n>>m;
    vector<lld> a(n+1),sum(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a.begin()+1,a.begin()+n+1);//边界要注意啊！！！
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    lld l=1,r=n;
    lld ans=0;
    while(l<=r){
        lld mid=(l+r)>>1;
        bool check=0;
        for(int i=1;i+mid-1<=n;i++){
            lld L=i,R=i+mid-1;
            if(a[R]*(mid-1)-(sum[R-1]-sum[L-1])<=m){
                check=1;
                break;
            }
        }
        if(check){
            l=mid+1;
            ans=mid;
        }
        else r=mid-1;
    }
    cout<<ans;
    return 0;
}
//哇！第一次在S组切题！
//谢谢谢谢！NOIP我来了！