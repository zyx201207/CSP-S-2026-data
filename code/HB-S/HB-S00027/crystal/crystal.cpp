#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,p[500100],p1[500100],p2[500005],p3[500005],a,b,c,d,e,ans=1;
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>p[i];
    sort(p+1,p+n+1);
    for(int i=1;i<=n;++i){
        p1[i]=p[i+1]-p[1];
        p2[i]=p[i+1]-p[i];
        if(i==1)p3[i]=0;
        else p3[i]=p3[i-1]+(p[i]-p[i-1])*(i-1);
    }
    for(int i=1,j=1;i<=n,j<=n;){
        a=p3[j],b=p3[i],c=p[j]-p[i],d=i-1,e=a-b-c*d;
        if(e<=m)ans=max(ans,j-i+1);
        if(e>m)++i;
        else{
            ans=max(ans,j-i+1),++j;
        }
        if(j>n||i>n)break;
        a=p3[j],b=p3[i],c=p[j]-p[i],d=i-1,e=a-b-c*d;
        if(e<=m){
            ans=max(ans,j-i+1);
        }
    }
    cout<<ans;
    return 0;
}
