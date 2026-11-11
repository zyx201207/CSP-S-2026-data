#include <bits/stdc++.h>
using namespace std;
const long long mx=10001000;
int i,j;
long long n,m,a[mx],b[mx],t;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long x=0,y=0;
    cin>>n>>m;
    for (i=0;i<=n;i++) a[i]=0,b[i]=0;
    for (i=1;i<=n;i++){
        cin>>a[i];
        b[i]=a[i];
        for(j=0;j<=n;j++){
            if(a[i]>=b[j])  {
                    t=a[i]-b[j];
            x+=t;
        if (x>=m)y++;break;
            }

        }
    }
    cout<<y;
    return 0;
}
