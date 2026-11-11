#include<iostream>
using namespace std;
#include<stdio.h>
constexpr int N=2e6+1;
int a[N];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,T,n,d,ans;
    cin>>c>>T;
    while(T--){
        ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1,i2,cnt;i<n-2;i++){
            i2=i;
            cnt=0;
            while(i2<=n && a[i2]-a[i]<d)++i2;
            if(i2>n)continue;
            if(a[i2]-a[i]>2*d)continue;
            for(int j=i;j<i2;j++){
                if(a[j+1]-a[j]>d)goto cont;
                cnt++;
            }
            if(cnt==2)++ans;
            cont:
                continue;
        }
        cout<<ans<<'\n';
    }
    return 0;
}