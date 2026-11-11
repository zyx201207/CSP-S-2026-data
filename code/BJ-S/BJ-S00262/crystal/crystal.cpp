#include<bits/stdc++.h>
using namespace std;
int n,ans;
long long m,a[500005],sum[500005];
bool check(int x,int ban){
    int energy=sum[x]-sum[ban];
    int al=a[x]*(x-ban);
    int need=abs(al-energy);
    return need<=m;
}
int main(){
    freopen("crystal.in","r",stdin);
    //freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        sum[i]=a[i]+sum[i-1];
    }
    for(int i=0;i<=n;i++){
        int L=i+1,R=n;
        while(L<R){
            int mid=(L+R+1)/2;
            if(check(mid,i)){
                L=mid;
            }else{
                R=mid-1;
            }
        }
        ans=max(ans,L-i);
    }
    cout<<ans;


}
