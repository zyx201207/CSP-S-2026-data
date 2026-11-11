#include <bits/stdc++.h>
using namespace std;
long long a[10005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m,mx=-1e9;
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++){
            long long x=i+1,c=a[i];
        for(int j=0;j<m-1;j++){
                for(int u=x;u<n;u++){
                    c=c&a[u];
                }
                x+=1;
        }
        mx=max(mx,c);
    }
    cout<<mx;
    return 0;
}
