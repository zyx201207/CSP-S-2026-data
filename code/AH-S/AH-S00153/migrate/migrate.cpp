#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
long long c,t,n,d,a[2000005],f[2000005],cnt[2000005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        memset(cnt,0,sizeof(cnt));
        memset(f,0,sizeof(f));
        int cntt=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                if(a[j]-a[1]<=d){
                    if(f[j]==1) cnt[j]++;
                    else cnt[j]=1;
                    f[j]=1;
                }else{
                    if(f[j]==f[j-1]+1) cnt[j]++;
                    else cnt[j]=1;
                    f[j]=f[j-1]+1;
                }
            }
        }for(int i=1;i<=n;i++){
            if(cnt[i]==2) cntt++;
        }
        cout<<cntt<<endl;
    }
    return 0;
}
