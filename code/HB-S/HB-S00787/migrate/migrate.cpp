//T3:56pts
#include<bits/stdc++.h>
using namespace std;
constexpr int N = 5000 + 10 , M = 2e6 + 10;
int c,T,n,ans,sum[M];
long long d,a[M];
int head,tail;
struct node{long long x;int y,z;} q[M];
int find1(long long x,int l,int r,int k){
    int mid=l+r>>1;
    while(l<=r){
        if(a[mid]<=x) l=mid+1;
        else k=mid,r=mid-1;
    }
    return k;
}
int find2(long long x,int l,int r,int k){
    int mid=l+r>>1;
    while(l<=r){
        if(a[mid]<=x) r=mid-1;
        else k=mid,l=mid+1;
    }
    return k;
}
signed main(){
    ios::sync_with_stdio(false),cin.tie(0);
    freopen("migrate.in","r",stdin),freopen("migrate.out","w",stdout);
    cin>>c>>T;
    if(c==11 || c==12){
        while(T--){
            cin>>n>>d;
            for(int i=1;i<=n;++i) cin>>a[i];
            if(n-(d/(a[2]-a[1]))*2<=0) cout<<0<<'\n';
            else if(d/(a[2]-a[1])>=2) cout<<n-(d/(a[2]-a[1]))*2+1<<'\n';
            else cout<<0<<'\n';
        }
        return 0;
    }
    while(T--){
        cin>>n>>d;
        for(int i=1;i<=n;++i) cin>>a[i];
        for(int i=n-1;i>=3;--i){
            head=1,tail=1,q[tail]={a[i+1],1,0},memset(sum,0,sizeof(sum)),sum[0]=1;
            for(int j=i;j>=1;--j){
                // cout<<head<<' '<<sum[q[head].z]<<' ';
                while(q[head].x-a[j]>d && head<=tail) sum[q[head].z]-=q[head].y,head++;
                // cout<<head<<' '<<sum[q[head].z]<<' ';
                if(sum[q[head].z]==2) {ans++;}
                // cout<<head<<' '<<sum[q[head].z]<<' '<<q[tail].x<<' '<<q[tail].y<<' '<<q[tail].z<<'\n';
                q[++tail]={a[j],sum[q[head].z],a[i+1]-a[j]<=d?1:q[head].z+1},sum[q[tail].z]+=sum[q[head].z];
                // cout<<head<<' '<<sum[q[head].z]<<' '<<q[tail].x<<' '<<q[tail].y<<' '<<q[tail].z<<'\n';
                if(head>tail) break;
            }
        }
        cout<<ans<<'\n';
        ans=0;
    }
    return 0;
}