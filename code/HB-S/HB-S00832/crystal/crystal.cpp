#include <bits/stdc++.h>

using namespace std;
const int N=5e5+10;
long long a[N],cnt,c[N],ans,mm;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cnt+=a[i];
    }
    long long x=a[1],mx=1,xz=1,mxx=a[1];
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++){
        if(a[i]==x){
            xz+=1;
        }
        else{
            if(mx<xz){
                mx=xz;
                mxx=x;
            }
            x=a[i];
            xz=1;
                }
    }
    cnt/=n;
    for(int i=1;i<=n;i++){
        c[i]=abs(a[i]-cnt);
    }
    sort(c+1,c+n+1);
    for(int i=1;i<=n;i++){
        mm+=c[i];
        if(mm<=m){
            ans++;
        }
        else {
            break;
        }
    }
    if(ans>mx){
        cout<<ans<<"\n";
        return 0;
    }
    ans=0;
    for(int i=1;i<=n;i++){
        c[i]=abs(a[i]-mxx);
    }
    sort(c+1,c+n+1);
    for(int i=1;i<=n;i++){
        mm+=c[i];
        if(mm<=m){
            ans++;
        }
        else {
            cout<<ans<<"\n";
            return 0;
        }
    }
    return 0;
}
