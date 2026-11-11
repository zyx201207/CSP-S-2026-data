#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long n,m,a[500005],d[500005],s[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++){
        d[i]=(a[i]-a[i-1])*(i-1);
        s[i]=s[i-1]+d[i];
    }
    for(int i=2;i<=n;i++)
        if(s[i]>m){
            cout<<i-1;
            return 0;
        }
}
