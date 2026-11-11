#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    unsigned long long n,m,i,l=1,r,b=0,c=0;
    cin>>n>>m;
    long long a[n+1];
    for(i=1;i<=n;i+=1){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    l=1;
    for(r=2;r<=n;r+=1){
        b+=(a[r]-a[r-1])*(r-l);
        while(b>m){
            b-=a[r]-a[l];
            l+=1;
        }
        c=max(r-l+1,c);
    }
    cout<<c;
    return 0;
}
