#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=514514;
ll n,m,a[MAXN]={},sumn=0,ans[MAXN]={},p[MAXN]={};
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    bool flagA=1;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        if(i>=3&&a[i]-a[i-1]!=a[i-1]-a[i-2]) flagA=0;
    }
    sort(a+1,a+n+1);
    ll mx=LLONG_MIN;
    if(flagA){
        int gc=(a[2]-a[1]);
        for(int i=1;i<=n;i++){
            if(gc*i*(i-1)/2==m){
                cout<<i;
                break;
            }else if(gc*i*(i-1)/2>m){
                cout<<i-1;
                break;
            }
        }
    }else{
        for(ll q=1;q<=n;q++){
            for(ll i=q;i<=n;i++){
                sumn=a[i]-a[i-1];
                ans[i]=ans[i-1]+(i-1)*sumn;
                if(ans[i]==m){mx=max(i,mx);break;}
                else if(ans[i]>m&&ans[i-1]<m){mx=max(i-1,mx);break;}
            }
        }
        cout<<mx;
    }

    return 0;
}
