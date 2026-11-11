#include<bits/stdc++.h>
using namespace std;
#define int long long
#define AC return 0
#define endl '\n'

const int N=5e5+5;

int n,m,a[N],sum=1,ans=-1;

signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        int tpm=m;
        sum=1;
        for(int j=i-1;j>=1;j--){
            if(tpm>=abs(a[j]-a[i])){
                tpm-=abs(a[j]-a[i]);
                sum++;
            }else{
                break;
            }
        }
        ans=max(sum,ans);
    }
    cout<<ans;
    AC;
}
