#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],s[250005],cnt;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    if(n<=5000){
        int mid=a[n/2+1];
        for(int i=1;i<=n;i++){
            if(a[i]>mid)    s[i]=-1;
            else s[i]=abs(mid-a[i]);
        }
        for(int i=n;i>0;i--){
            if(m>=s[i]&&s[i]>=0)
                m-=s[i],cnt++;
        }
        cout<<cnt;
        return 0;
    }
    if(m>=abs(a[2]-a[1])*(n*(n-1)>>1)){
        cout<<n;
        return 0;
    }
    int i=1;
    while(a[n]-a[i++]<=abs(a[2]-a[1])*(n*(n-1)/2)-m);
    cout<<n-i+1;
    return 0;
}
