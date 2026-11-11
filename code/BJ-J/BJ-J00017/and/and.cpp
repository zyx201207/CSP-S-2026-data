#include <bits/stdc++.h>
using namespace std;

const int N=2e5+10;
int n,m,a[N],ans;

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=30;i>=0;i--){
        int cnt=0;
        for(int j=1;j<=n;j++){
            if(a[j]&(1<<i)) cnt++;
        }
        if(cnt>=m){
            ans|=(1<<i);
            for(int j=1;j<=n;j++){
                if(!bool(a[j]&(1<<i))) a[j]=0;
            }
        }
    }
    cout<<ans;
}
