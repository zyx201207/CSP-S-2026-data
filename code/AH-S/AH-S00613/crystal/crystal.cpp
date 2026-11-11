#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],resum[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=2;i<=n;i++){
        resum[i]=a[i]-a[i-1];
    }
    long long sum=0,len=1,first=1,ans=1;
    for(int i=2;i<=n;i++){
        sum+=resum[i]*len;
        len++;
        for(;first<=i&&sum>m;first++){
            sum-=a[i]-a[first];
            len--;
        }
        ans=max(ans,len);
    }
    cout<<ans<<endl;



    return 0;
}
/*
5 5
1 2 4 8 9
  1 2 4 1
0 1 5 17
*/
