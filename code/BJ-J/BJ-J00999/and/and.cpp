#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n,m,a[N],ans;
main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=pow(2,n);i++){
        int t=i,cnt=0,pos=0,sum=0;
        bool b[30];
        memset(b,0,sizeof(b));
        while(t){
            b[cnt]=t%2;
            t/=2;
            cnt++;
        }
        if(cnt!=m) continue;
        for(int j=0;j<cnt;j++){
            if(b[j]){
                sum=a[j+1];
                pos=j;
                break;
            }
        }
        for(int j=pos+1;j<cnt;j++){
            if(b[j]) sum=sum&a[j+1];
        }
        ans=max(ans,sum);
    }
    cout<<ans;
}
//rp++rp++rp++