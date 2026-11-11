#include<bits/stdc++.h>
using namespace std;
long long n,m,c[500005],a[500005],f;
int maxn=0;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.in","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    sort(c+1,c+n+1);
    for(int i=2;i<=n;i++){
        f=m;
        int ans=1;
        for(int j=i-1;j>=1;j--){
            if(f>=c[i]-c[j]){
                f-=c[i]-c[j];
                ans++;
            }else{
                break;
            }
        }
        maxn=max(maxn,ans);
    }
    cout<<maxn;
    return 0;
}
