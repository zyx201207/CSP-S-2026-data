#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll maxn=500005;
ll n,m,a[maxn],sp,ans;
ll h=1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+1+n);
    /*for(int i=1;i<=n;i++){
        cout<<a[i]<<' ';
    }
    cout<<endl;*/
    for(int i=1;i<=n;i++){
        if(a[i]!=a[i-1]){
            sp+=(i-h)*(a[i]-a[i-1]);
        }
        while(sp>m){
            sp-=(a[i]-a[h]);
            h++;
        }
        //cout<<i<<' '<<sp<<endl;
        ans=max(ans,i-h+1);
    }
    printf("%lld\n",ans);
    return 0;
}
/*
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll maxn=500000;

int main(){
    freopen("hack.in","w",stdout);
    cout<<"500000 1000000000000000000"<<endl;
    for(int i=1;i<maxn;i++){
        cout<<"-1000000000000 ";
    }
    cout<<"1000000000000"<<endl;
    return 0;
}
*/
