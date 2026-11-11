#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    int a[200001]={};
    int b;
    int start=1;
    char c;
    for(int i=1;i<=n;i++){
        cin>>b>>c;
        for(int i=start;i<=b;i++){
            a[i]=c;
            start=b+1;
        }
    }
    int ra[200001]={};
    int cnt=1;
    for(int i=n;i>=1;i--){
        ra[cnt]=a[i];
        cnt++;
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(a[i]!=ra[i]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
