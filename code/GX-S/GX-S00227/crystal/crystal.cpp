#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+2;
int n,m;
int a[N],s[N];
int ans=1;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    // my s write wrong so my time -30min
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
    cin>>n>>m;
    s[0]=0;
    for(int i=1;i<=n;i++) {
            cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    for(int i=1,j=1;i<=n&&j<=n;i++){
        while(a[i]*(i-j)-(s[i-1]-s[j-1])>m){
            j++;
        }
        //cout<<j<<' ';


        ans=max(ans,i-j+1);
    }
   // cout<<s[2]<<' '<<s[1]<<'\n';
    cout<<ans;


    return 0;
}
