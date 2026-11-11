#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005],b[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    long long l=1,maxx=0;
    for(int i=1;i<=n;i++){
        b[i]=b[i-1]+a[i];
        while((i-l+1)*a[i]-b[i]+b[l-1]>m){
            l++;
        }
        maxx=max(maxx,i-l+1);
    }
    cout<<maxx;
    return 0;
}
