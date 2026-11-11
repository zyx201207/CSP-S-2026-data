#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
int n;
ll m,a[N],d[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+1+n);
    bool f=true;ll s=0;
    for(int i=1;i<n;i++){
        d[i]=a[i+1]-a[i];
        if(i>1&&d[i]!=d[i-1])f=false;
        s+=d[i]*i;
    }
    if(s<=m){
        cout<<n;
        return 0;
    }
    if(f){
        ll dd=d[1];
        for(int i=1;i<n;i++){
             m-=dd*i;
            if(m<0){
                cout<<i-1;
                return 0;
            }
        }
    }
    int ans=0;
    for(int i=1;i<n;i++){
        int h=i+1;ll s=m;
        while(s>=0&&h<=n){
            s-=d[h-1]*(h-i);
            h++;
        }
        ans=max(ans,h-i-1);
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
