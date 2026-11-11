#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=5e5+5;
int n,m;
int a[MAXN];
int ans=0;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int cnt=m;
    for(int i=1;i<=n;i++){
        int nx=a[i+1]-a[i];
        if(nx>=0 && (nx*i)<=cnt){
            ans=i;
            cnt-=nx*i;
            for(int j=1;j<=i;j++){
                a[j]=a[i+1];
            }
            for(int j=i+1;j<=n;j++){
                if(a[j]==a[i]) ans++;
            }
        }
        if(nx>cnt){
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}
