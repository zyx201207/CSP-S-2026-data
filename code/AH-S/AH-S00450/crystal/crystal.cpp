#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500050];
int s[500050];
int l,r,mid,ans;
int n,m;
int i,j;

bool check(int x){
    int i,j,res=0x7fffffffffffffff;
    int l,r;
    for(i=1;i+x-1<=n;i++){
        l=i;r=i+x-1;
        res=min(res,a[r]*x-(s[r]-s[l-1]));
    }
    return res<=m;
}

signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
    }
    l=1;r=n;
    while(l<=r){
        mid=(l+r)/2;
        //printf("%d %d\n",l,r);
        if(check(mid)){
            ans=mid;
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    cout<<ans;
    return 0;
}
