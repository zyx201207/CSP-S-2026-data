#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct nd{
    ll sl,xg;
    string zf;
}a[200005];
ll n,cnt,ans,gm;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i].sl>>a[i].zf;
    cnt=n;
    for(int i=1;i<=n;i++){
        for(cnt;cnt>=1;cnt--){
            if(a[i].zf!=a[cnt].zf&&a[i].xg==0){
                if(a[i].sl<a[cnt].sl){
                    ans+=a[i].sl;
                    a[cnt].sl-=a[i].sl;
                    a[i].sl=0;
                    break;
                }else{
                    ans+=a[cnt].sl;
                    a[cnt].xg=1;
                    a[i].sl-=a[cnt].sl;
                    a[cnt].sl=0;
                }
            }else {
                if(a[i].sl<a[cnt].sl){

                    a[cnt].sl-=a[i].sl;
                    a[i].sl=0;
                    break;
                }else{
                    a[cnt].xg=1;
                    a[i].sl-=a[cnt].sl;
                    a[cnt].sl=0;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}

