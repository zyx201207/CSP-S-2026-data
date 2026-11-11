#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005];
int main(){
    foreopen("crystal.in","r",stdin);
    foreopen("crystal.out","w",stdout);
    cin>>n>>m;
    long long cnt=1;
    for(int i=1;i<=n;i++){
            cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=2;i<=n;i++){
        b[i-1]=a[i];
    }
    long long t=m;
    long long maxx=0;
    for(int i=1;i<=n-1;i++){
        for(int j=1;j<=i;j++){
            if(abs(b[i]-a[i+1-j])<=t){
                t-=abs(b[i]-a[i+1-j]);
                cnt++;
            }
        }
        t=m;
        maxx=max(maxx,cnt);
        cnt=1;
    }
    cout<<maxx;
    return 0;
}
