#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],q,h,p[500005];
int k=1;

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        q=q+a[i];

    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        p[i]=p[i-1]+a[i];
    }
    h=q+m;
    if(n<=5000){
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                if(i*a[j]<=p[j]-p[j-i-1]+m){
                    k=max(k,i);
                }
            }
        }
        cout<<k;
        return 0;
    }
    for(int i=n;i>=1;i--){
        if(i*a[i]<=h){
            cout<<i;
            return 0;
        }
        h=h-a[i];
    }
}
