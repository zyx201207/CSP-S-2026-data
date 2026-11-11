#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
using ll=long long;
const int N=2e6+10;
int c,t,n;
ll d,x[N],ans;
ll len[N],tim[N];
int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>x[i];
        for(int l=1;l<=n;l++){
            memset(len,0x3f,sizeof(len));
            len[l]=0;
            memset(tim,0,sizeof(tim));
            for(int r=l;r<=n;r++){
                for(int k=lower_bound(x+l,x+r,x[r]-d)-x;k<r;k++){
                    if(len[k]+1<len[r]) len[r]=len[k]+1,tim[r]=1;
                    else if(len[k]+1==len[r]) tim[r]++;
                }
                if(tim[r]==2) ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}