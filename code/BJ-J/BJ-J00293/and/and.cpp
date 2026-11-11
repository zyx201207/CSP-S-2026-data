#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
ll a[N];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==1){
        sort(a+1,a+n+1);
        cout<<a[n];
        return 0;
    }
    ll ans=0;
    if(n<=20){
        for(int i=1;i<=(1<<n)-1;i++){
            int cnt=0;
            int num=0;
            ll sum=0;
            int x=i;
            while(x){
                cnt++;
                if(x&1){
                    num++;
                    if(num==1) sum=a[cnt];
                    else sum&=a[cnt];
                }
                x>>=1;
            }
            if(num!=m) continue;
            ans=max(ans,sum);
        }
        cout<<ans;
    }
    return 0;
}