#include<bits/stdc++.h>
using namespace std;
const int N=2000005;
long long n,d,x[N];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c,t;
    bool fA=0;
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        long long dd,ans=0;
        for(int i=1;i<=n;i++){
            cin>>x[i];
            if(i>2){
                dd=x[2]-x[1];
                if(x[i]-x[i-1]!=dd)fA=1;
            }
        }
        if(fA==0){
            if(dd>d){
                cout<<"0\n";
            }else{
                cout<<n-(d/dd)*2+1LL<<"\n";
            }
            continue;
        }
        for(int i=1;i<=n-3;i++){
            for(int j=i+3;j<=n;j++){
                int cnt=0;
                for(int k=i+1;k<j;k++){
                    if(x[k]-x[i]<=d&&x[j]-x[k]<=d)cnt++;
                }
                if(cnt==2)ans++;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
