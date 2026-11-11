#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+78;
long long n,m;
long long a[N];
long long ans=1;
long long cha;
bool flag=1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    if(n==1){
        cout<<1;
        return 0;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i>=2){
            cha=a[2]-a[1];
            if(a[i]-a[i-1]!=cha)flag=0;
        }
    }
    if(flag){
        cout<<1<<endl;
        cout<<min(m/cha+1,n);
        return 0;
    }
    sort(a+1,a+n+1);
    for(int i=n;i>=1;i--){
        if(ans>=i)break;
        long long tmp=m,cnt=1;
        for(int j=i-1;j>=0;j--){
            if(tmp>=a[i]-a[j]){
                tmp-=a[i]-a[j];
                cnt++;
            }
        }
        ans=max(cnt,ans);
    }
    cout<<ans;
    return 0;
}
