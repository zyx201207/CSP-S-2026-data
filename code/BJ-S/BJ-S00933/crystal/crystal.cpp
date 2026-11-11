#include<bits/stdc++.h>
#define N 500010
#define int long long
using namespace std;

int n,m;
int a[N],s[N];

int find(int temp){
    int l=1,r=temp;
    while(l<r){
        int mid=(l+r)/2;
        int t=(temp-mid+1)*a[temp]-(s[temp]-s[mid-1]);
        if(t<=m) r=mid;
        else l=mid+1;
    }
    return r;
}

signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    long long mx=0;
    for(int i=1;i<=n;i++){
        mx=max(mx,i-find(i)+1);
    }
    cout<<mx;
    return 0;
}
