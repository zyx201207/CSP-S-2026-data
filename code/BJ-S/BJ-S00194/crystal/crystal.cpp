#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,d,cnt,ans;
int a[N];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        d=a[i];
        int w=m;
        cnt=1;
        for(int j=i-1;j>=1 && w-(d-a[j])>=0;j--){
            w-=d-a[j];
            cnt++;
        }
        ans=max(ans,cnt);
    }
    //cout<<1<<endl;
    cout<<ans<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
