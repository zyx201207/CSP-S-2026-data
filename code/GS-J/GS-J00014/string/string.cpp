#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200005],o,s,p;
char c[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
    for(int i=1,j=n;i<j;){
        o=min(a[i],a[j]);
        if(c[i]!=c[j])s+=o;
        a[i]-=o,a[j]-=o;
        if(!a[i])++i;
        if(!a[j])--j;
    }cout<<s;
    return 0;
}
