#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,s,ans;
char a[100000005],c;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++){
        cin>>s>>c;
        m+=s;
        for(ll j=m-s+1;j<=m;j++){
            a[j]=c;
        }
    }
    if(m%2==0){
        for(ll i=m/2,j=m/2+1;i>=1,j<=m;i--,j++){
            if(a[i]!=a[j]){
                ans++;
            }
        }
    }
    else{
        for(ll i=m/2+1,j=m/2+1;i>=1,j<=m;i--,j++){
            if(a[i]!=a[j]){
                ans++;
            }
        }
    }
    printf("%lld",ans);
    return 0;
}
