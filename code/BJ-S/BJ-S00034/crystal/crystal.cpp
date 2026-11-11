#include<iostream>
#include<algorithm>
using namespace std;
const int N=5e5+10;
long long a[N];
long long pre[N];
long long m;
bool check(long long i,long long mid){
    return ((mid-i)*a[mid]-(pre[mid-1]-pre[i-1]))<=m;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    pre[0]=0;
    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1]+a[i];
    }
    int ans=0;

    for(int i=1;i<=n;i++){
        int l=i,r=n;
        int nowanss=0,mid;
        while(l<=r){
            mid=l+r>>1;
            if(check(i,mid)){
                nowanss=mid-i+1;
                l=mid+1;
            }else r=mid-1;
        }
        ans=max(ans,nowanss);
    }
    cout<<ans;
    return 0;
}
