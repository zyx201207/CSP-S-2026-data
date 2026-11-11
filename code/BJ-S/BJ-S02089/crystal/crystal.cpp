#include<bits/stdc++.h>
#define int long long
using namespace std;
long long n,m,a[500005],q[500005],maxx=0;
bool cmp(int aa,int bb){
    return aa<bb;
}
bool check(int z,int y){
    int nn=(z-1)*(a[y]-a[z]);
    if(q[y]-(nn+q[z])<=m){
        return true;
    }
return false;
}
long long erfen(int x){
    if(check(1,x)){
        return x;
    }
    int l=1,r=x,ans=x;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid,x)){
            ans=mid;
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    ans=x-ans+1;
    return ans;
}
signed main(){
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n;i++){
    cin>>a[i];
}
sort(a+1,a+n+1,cmp);
q[1]=0;
for(int i=2;i<=n;i++){
    if(a[i]==a[i-1]){
        q[i]=q[i-1];
    }else{
        long long cha=a[i]-a[i-1];
        long long c=(i-1)*cha;
        q[i]=q[i-1]+c;
    }
}
for(int i=n;i>0;i--){
    maxx=max(maxx,erfen(i));
}
cout<<maxx;
return 0;
}
