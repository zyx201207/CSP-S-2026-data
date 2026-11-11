#include<bits/stdc++.h>
using namespace std;
const  int N=10050;
long long n,m,a[N],sum,ans,mid;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a,a+n+1);
    mid=a[(n+1)/2];
    for(long long i=1;i<=n;i++){
            if(a[i]<=mid){
                if(mid-abs(a[i])<=m) m-=mid-a[i],ans++;
            }

    }
    cout<<ans;
    return 0;
}
