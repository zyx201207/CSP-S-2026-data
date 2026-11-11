#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,l,r;
long long a[N],ans,tmp;
char c[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
    l=1,r=n;
    while(l<r){
        tmp=min(a[l],a[r]);
        if(c[l]!=c[r])ans+=tmp;
        a[l]-=tmp,a[r]-=tmp;
        if(!a[l])l++;
        if(!a[r])r--;
    }
    cout<<ans<<'\n';
    return 0;
}