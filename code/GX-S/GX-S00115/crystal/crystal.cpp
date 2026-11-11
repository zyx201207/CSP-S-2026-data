#include<bits/stdc++.h>
using namespace std;
long a[600000],st[600000];//st:i to n all
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;long m;
    int maxx=-1;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=n-1;i>=1;i--){
        st[i]=st[i+1]+(a[n]-a[i]);
    }//i,j to n: st[i]-st[j]
    //i to j: (i,j to n)-(a[n]-a[j])*(n-j)
    for(int i=n;i>=1;i--){
        int l=1,r=i;
        while(l<r){
            int mid=(l+r)>>1;
            int sum=st[mid]-st[i]-(a[n]-a[i])*(i-mid);
            if(sum>m)l=mid+1;
            else r=mid-1;
        }
        int ans=i-l+1;
        maxx=max(maxx,ans);
    }
    cout<<maxx;
    return 0;
}
