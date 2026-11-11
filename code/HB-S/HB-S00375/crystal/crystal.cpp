#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[600100];
int bk[1000];
int ans=0,js,k;
bool e=1;
int f,v,jjs;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i>2&&a[i]-a[i-1]!=a[i-1]-a[i-2]){
            e=0;
        }
    }
    if(e){
        f=a[2]-a[1];
        v=1;
        ans=1;
        jjs=0;
        while(ans<n&&jjs+v*f<=m){
            jjs+=v*f;
            v++;
            ans++;
        }
        cout<<ans;
        return 0;
    }
    for(int i=1;i<=n;i++){
        bk[a[i]+100]++;
    }
    for(int i=0;i<=200;i++){
        if(bk[i]==0){
            continue;
        }
        js=0;
        k=m;
        for(int j=i;j>=0;j--){
            if((i-j)*bk[j]>k){
                js+=(k/(i-j));
                break;
            }
            js+=bk[j];
            k-=(i-j)*bk[j];
        }
        ans=max(js,ans);
        //cout<<i<<" "<<js<<"\n";
    }
    cout<<ans;
    return 0;
}
