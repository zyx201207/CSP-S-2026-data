#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin>>n;
    vector<unsigned long long> a(n);
    vector<char> c(n);
    unsigned long long aa=0;
    for(unsigned long long i=0;i<n;i++)cin>>a[i]>>c[i],aa+=a[i];
    unsigned long long ans=0;
    unsigned long long l=a[0],r=a[n-1],ll=0,rr=n-1;
    for(unsigned long long g=0;g<aa/2;g++){
        if(c[ll]!=c[rr])ans++;
        l--,r--;
        if(l==0)ll++,l=a[ll];
        if(r==0)rr--,r=a[rr];
    }
    cout<<ans;
    return 0;
}