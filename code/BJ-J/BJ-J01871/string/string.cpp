#include <bits/stdc++.h>
using namespace std;
#define ll long long 
const int N=2e5+9;
int n,a[N];
char b[N];
ll m,ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
    for(int i=1;i<=n;i++)m+=a[i];
    ll i=1;
    for(int c1=1,c2=n,d1=0,d2=0;i<=m/2;){
        int t=min(a[c1]-d1,a[c2]-d2);
        if(b[c1]!=b[c2])ans+=t;
        d1+=t,d2+=t,i+=t;
        if(d1>=a[c1])c1++,d1=0;
        if(d2>=a[c2])c2--,d2=0;
    }
    cout<<ans;
    return 0;
}