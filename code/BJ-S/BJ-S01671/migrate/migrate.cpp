#include<iostream>
using namespace std;
int c,T;
int n;
long long d;
long long a[2000010];
long long cnt[2000010],stp[2000010];
void run(){
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    long long ans=0;
    for(int i=1;i<=n;i++){
        cnt[i]=1;
        stp[i]=0;
        for(int j=i+1;j<=n;j++){
            cnt[j]=0;
            stp[j]=0x3f3f3f3f;
            for(int k=j-1;k>=i;k--){
                if(a[j]-a[k]<=d){
                    if(stp[j]>stp[k]+1){
                        stp[j]=stp[k]+1;
                        cnt[j]=cnt[k];
                    }
                    else if(stp[j]==stp[k]+1){
                        cnt[j]+=cnt[k];
                    }
                }
                else{
                    break;
                }
            }
            if(cnt[j]==2){
                ans++;
            }
        }
    }
    cout<<ans<<endl;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>T;
    while(T--){
        run();
    }
    return 0;
}
