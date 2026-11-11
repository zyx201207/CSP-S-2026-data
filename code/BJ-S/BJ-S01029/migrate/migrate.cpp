#include<bits/stdc++.h>
using namespace std;
const int MAXN=500+2,MAXM=5000+2;
long long ccc,T,n,d,a[MAXN],sum,ans[MAXN],cnt,ttttt,ttt;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>ccc>>T;
    if(ccc==11||ccc==12){
        while(T--){
            cin>>n>>d>>ttttt>>ttt;
            ttt-=ttttt;
            for(int i=3;i<=n;i++)
                cin>>ttttt;
            if(d>=2*(ttt))//&&d<3*(ttt))
                cout<<max(0ll,n-d/ttt-d/ttt+1)<<endl;
            else
                cout<<0<<endl;
        }
        return 0;
    }
    while(T--){
        memset(ans,0,sizeof(ans));cnt=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                sum=0;
                for(int k=i+1;k<j;k++){
                    if(a[k]-a[i]<=d&&a[j]-a[k]<=d)
                        sum++;
                }
                if(sum==2&&a[j]-a[i]>d)
                    ans[i]++;
            }
        }
        for(int i=n-2;i>=1;i--){
            for(int j=i+1;j<=i+1;j++)
                if(a[j]-a[i]<=d&&a[j+1]-a[i]>d){
                    ans[i]+=ans[j];
                    break;
                }
            cnt+=ans[i];
        }
        cout<<cnt<<endl;
    }
}
