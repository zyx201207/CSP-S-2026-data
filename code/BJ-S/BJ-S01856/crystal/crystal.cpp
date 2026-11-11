#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ll n,m,a[500005]={0};
    cin>>n>>m;
    for(int i=0;i<n;i++){
        scanf("%lld",a+i);
    }
    sort(a,a+n);
    int l=0,sum=0,mx=1;
    for(int r=1;r<n;r++){
        sum+=((r-l)*(a[r]-a[r-1]));
        while(sum>m){
            sum-=(a[r]-a[l]);
            l++;
        }
        if(r-l+1>mx) mx=r-l+1;
    }
    cout<<mx;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
