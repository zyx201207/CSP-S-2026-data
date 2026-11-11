#include<bits/stdc++.h>
#define int long long
#define fr(i,l,r) for(int (i)=(l);(i)<=(r);(i)++)
#define fd(i,l,r) for(int (i)=(r);(i)>=(l);(i)--)
using namespace std;

const int N=2e5+10;
int a[N];
char c[N];

signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;cin>>n;
    fr(i,1,n)cin>>a[i]>>c[i];
    int l=1,curl=0,curr=0,r=n,ans=0;
    while(l<r){
        if(a[l]-curl<=a[r]-curr){
            if(c[l]!=c[r])ans+=a[l]-curl;
            curr+=a[l]-curl,curl=0,l++;
        }else{
            if(c[l]!=c[r])ans+=a[r]-curr;
            curl+=a[r]-curr,curr=0,r--;
        }
    }
    cout<<ans<<'\n';
}