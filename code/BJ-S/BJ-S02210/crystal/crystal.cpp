#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],mx,b,r=1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    b=m;
    for(long long l=1;l<=n;l++){
        b+=a[l-1];
        while(1){
            if(b>=(r-l)*(a[r+1]-a[r])&&r<n){
                b-=(r-l)*(a[r+1]-a[r]);
                r++;
            }else break;
        }
        mx=max(mx,r-l+1);
    }
    cout<<mx;
    fclose(stdout);
    fclose(stdin);
    return 0;
}
