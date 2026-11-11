#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t;
int a[2000005],far[2000005];
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        int n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++){
            bool f=0;
            for(int j=i+1;j<=n;j++){
                if(a[j]-a[i]>d){
                    far[i]=j-1;
                    f=1;
                    break;
                }
            }
            if(f==0) far[i]=n;
            //cout<<far[i]<<' ';
        }
        //continue;
        int cnt=0;
        for(int i=1;i<=n;i++){
            int cnt1=0,cnt2=0;
            for(int j=i+3;j<=n;j++){
                int k=i+1;
                bool f=1;
                while(k<j){
                    cnt1++;
                    if(far[k]!=k) k=far[k];
                    else{
                        f=0;
                        break;
                    }
                }
                k=far[i];
                while(k<j){
                    cnt2++;
                    if(far[k]!=k) k=far[k];
                    else{
                        f=0;
                        break;
                    }
                }
                if(f&&cnt1==cnt2) cnt++;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
