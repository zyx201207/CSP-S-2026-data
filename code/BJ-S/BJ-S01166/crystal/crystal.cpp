# include <bits/stdc++.h>
using namespace std;
long long n,m;
const int N=5e5+10;
long long a[N];
long long pre_a[N];
long long ans=0;
int check(int x,int id){
    long long use=x*a[id]-(pre_a[id-1]-pre_a[id-x-1]);
    return use<=m;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        pre_a[i]=pre_a[i-1]+a[i];
        int l=0,r=i-1;
        while(l<=r){
            int mid=l+r>>1;
            if(check(mid,i)){
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        ans=(l>ans?l:ans);
    }
    cout<<ans;
    return 0;
}
