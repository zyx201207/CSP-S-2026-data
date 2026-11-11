#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,ans=0;
long long m;
long long a[N],sum[N];
bool check(long long mid,int id){
    return id*mid-sum[id]<=m;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    sum[0]=0;
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
        bool f=check(a[i],i);
        if(f){
            ans=i;
        }else{
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}
