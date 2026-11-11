#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=200005;
int n,a[N];
char c[N];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    int l=1,r=n,ans=0;
    while(l<r){
        //for(int i=1;i<=n;i++){
        //    cout<<a[i]<<' '<<c[i]<<endl;
        //}
        //cout<<"l="<<l<<' '<<"r="<<r<<endl;
        int x=min(a[l],a[r]);
        if(c[l]!=c[r]){
            ans+=x;
        }
        a[l]-=x;
        a[r]-=x;
        if(a[l]==0){
            l++;
        }
        if(a[r]==0){
            r--;
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
