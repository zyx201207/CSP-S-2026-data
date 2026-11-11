#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int N=2e5+10;
ll n,k=0;
char s[N];

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%lld",&n);
    for(register int i=1; i<=n;i++){
        ll a;
        char c;
        scanf("%lld",&a);
        cin>>c;
        for(register int j=1; j<=a;j++){
            k++;
            s[k]=c;
        }
    }
    ll ans=0;
    for(register int i=1,j=k; i<=j;i++,j--){
        if(s[i]!=s[j]) ans++;
    }
    printf("%lld",ans);
    return 0;
}
