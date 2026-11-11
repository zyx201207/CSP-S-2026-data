#include<bits/stdc++.h>
using namespace std;
const int N=200005;
char cc[N],c[N];
long long mid,n,a[N],aa[N],sum,r,l,now,ans,al;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        sum+=a[i];
    }
    l=1,r=n;
    while(l<r){
        if(c[l]!=c[r])ans+=min(a[r],a[l]);
        al=a[l];
        a[l]-=a[r];
        a[r]-=al;
        if(a[l]<=0)l++;
        if(a[r]<=0)r--;
    }
    cout<<ans;
}
