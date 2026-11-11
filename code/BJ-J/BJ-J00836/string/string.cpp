#include <bits/stdc++.h>
#define N int(2e5+10)
using namespace std;
typedef long long ll;
ll n,l,ans,limit=-1e18;
ll a[N];
char c[N];
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i]>>c[i];
        l+=a[i];
        limit=max(limit,a[i]);
    }
    if(limit*n<=100000000){
        string s="";
        for(int i=1;i<=n;++i)
            for(int j=1;j<=a[i];++j) s+=c[i];
        for(int i=0;i<l;++i)
            if(s[i]!=s[l-i-1]) ++ans;
        cout<<ans/2;
        return 0;
    }
    ll temp1=0;
    ll pos;
    for(int i=1;i<=n;++i){
        temp1+=a[i];
        if(temp1>=l/2){
            pos=i;
            break;
        }
    }
    temp1=a[1];
    ll temp2=0;
    for(int i=1,j=n;i<=pos&&j>pos;){
        temp2+=a[j];
        if(temp1>=temp2){
            if(c[i]!=c[j]){
                ans+=a[j];
                --j;
            }
        }else{
            ++i;
            temp1+=a[i];
            if(c[i]!=c[j]){
                ans+=a[j];
                --j;
            }
        }
    }
    cout<<ans;
    return 0;
}
