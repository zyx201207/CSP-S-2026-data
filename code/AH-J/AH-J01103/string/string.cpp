#include<bits/stdc++.h>
using namespace std;
int n,s;
long long a[200010];
char c[200010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int i;
    cin>>n;
    for(i=1;i<=n;i++)cin>>a[i]>>c[i];
    int l=1,r=n,m=3;
    while(l<r){
        long long mi=min(a[l],a[r]);
        a[l]-=mi;
        a[r]-=mi;
        if(c[l]!=c[r])s+=mi;
        if(!a[l])l++;
        if(!a[r])r--;
    }
    cout<<s;
}
