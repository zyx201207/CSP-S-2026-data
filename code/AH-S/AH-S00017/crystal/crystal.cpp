#include<iostream>
#include<algorithm>
#include<cstdio>
#define int long long
using namespace std;
bool flag;
int n,m,a[500005],sum[500005],ans,pos;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
    }
    for(int i=2;i<=n;i++){
        if(a[i]-a[i-1]!=a[2]-a[1]) flag=1;
    }
    if(!flag){
        for(int i=1;i<=n;i++){
            m-=i*(a[2]-a[1]);
            if(m<0){
                cout<<i;
                break;
            }
        }
        return 0;
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            int tmp=(j-i)*a[j]-(sum[j-1]-sum[i-1]);
            if(tmp<=m){
                int tmp1=j-i+1;
                if(pos<tmp1){
                    pos=tmp1;
                }
            }
        }
    }
    cout<<pos;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
/*chu yi tiao zhan -S   tiao zhan shi bai*/
