#include<iostream>
#include<algorithm>
using namespace std;
int n,m,ans;
long long a[500005],frt[500005];
int main(){
    freopen("crystal3.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        frt[i]=frt[i-1]+a[i];
    }
    sort(a+1,a+n+1);
    int l=1,r=n;
    while(l<=r){
        int mid=(l+r)>>1,sum=-1;
        for(int i=1;i<=mid;i++){
            if(a[mid]*(mid-i+1)-frt[mid]+frt[i-1]<=m) sum=max(sum,mid-i+1);
        }
        if(sum!=-1){
            l=mid+1;
            ans=max(ans,sum);
        }
        else r=mid-1;
    }
    cout<<ans;
    return 0;
}
