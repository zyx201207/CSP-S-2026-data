#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=500005;
void read(int &x){
    int f=1;x=0;char s=getchar();
    while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
    while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
    x*=f;
}
int n,m,a[N],sum[N];
bool check(int mid,int i){
    if((i-mid+1)*a[i]-(sum[i]-sum[mid-1])<=m) return 1;
    return 0;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    // freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    read(n);read(m);
    for(int i=1;i<=n;i++){
        read(a[i]);
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        int l=1,r=i,as=i;
        while(l<=r){
            int mid=(l+r)>>1;
            if(check(mid,i)){
                as=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        ans=max(ans,i-as+1);
    }
    cout<<ans;
    return 0;
}
//g++ crystal.cpp -o crystal -std=c++14 -O2 "-Wl,-stack=1234567890" -Wall