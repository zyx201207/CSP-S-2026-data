#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+5;
ll c,t,n,d,x[N],cnt,lm,ans;
void Move(int il,int len,int ed){
    if(il==ed){
        if(len<lm){
            lm=len;
            cnt=1;
        }else if(len==lm)cnt++;
        return;
    }
    for(int i=il+1;i<=ed;i++){
        if(x[i]-x[il]>d)break;
        Move(i,len+1,ed);
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>t;
    while(t--){
        ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>x[i];
        for(int i=1;i<=n-3;i++){
            for(int j=i+3;j<=n;j++){
                cnt=0;lm=2e6+1;
                Move(i,0,j);
                if(cnt==2)ans++;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}