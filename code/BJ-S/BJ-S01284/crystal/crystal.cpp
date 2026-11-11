#include <bits/stdc++.h>
using namespace std;
const long long N=5e5+10;
long long n,m,a[N],l=1,s=0,ans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(long long i=1;i<=n;i++){
        // cout<<i<<":"<<endl;
        s+=(i-l)*(a[i]-a[i-1]);
        // cout<<s<<endl;
        while(s>m){
            s-=a[i]-a[l];
            l++;
            // cout<<"->"<<l<<" "<<s<<endl;
        }
        ans=max(ans,i-l+1);
        // cout<<"["<<l<<","<<i<<"]"<<endl;
    }
    cout<<ans<<endl;
    return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/