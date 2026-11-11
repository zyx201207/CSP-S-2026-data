#include<iostream>
#include<algorithm>
using namespace std;
long long a[500005],d[500005],s[500005],n,m;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>> n >> m;
    for(int i=1;i<=n;i++){
            cin>> a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
            d[i]=a[i]-a[i-1];
    }
    int ans=1,l=0;
    for(int i=1;i<=n;i++){
        m-=d[i]*(i-l-1);
        while(m<0){
                l++;
                m+=a[i]-a[l];
        }
        ans=max(ans,i-l);
    }
    cout<< ans;
    return 0;
}
