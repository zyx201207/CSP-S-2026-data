#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int C,T;
int n;
long long a[N],d;
int dis[N];
int pos[N<<1];
long long g[N];
long long ans;
int Find(long long x)
{
    int l=1;
    int r=n;
    while(l<=r){
        int mid=(l+r)>>1;
        if(a[mid]<=x)
            l=mid+1;
        else
            r=mid-1;
    }
    return r;
}
void debug()
{
    for(int i=1;i<=n;i++)
        cout<<i<<" "<<dis[i]<<' '<<g[i]<<'\n';
    cout<<'\n';
    return ;
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>C>>T;
    while(T--){
        ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++)
            cin>>a[i];
    for(int s=1;s<n;s++){
        dis[s]=0;
        for(int i=s;i<n;){
            int j=Find(a[i]+d);
            for(int k=i+1;k<=j;k++){
                dis[k]=dis[i]+1;
            }
            pos[dis[i]+1]=i+1;
            if(i>=j){
                dis[i+1]=dis[i]+2;
                g[i+1]=1;
                j++;
            }
            i=j;
        }
        g[s]=1;
        pos[0]=1;
        for(int i=1;i<=dis[n];i++){
            for(int j=pos[i-1];j<pos[i];j++){
                int t=Find(a[j]+d);
                if(t>=pos[i]){
                    g[t]+=g[j];
                }
            }
            for(int j=max(n,pos[i+1]-1);j>=pos[i];j--){
                g[j]=g[j]+g[j+1];
            }
        }
    //    debug();
        for(int i=s;i<=n;i++){
            ans+=(g[i]==2);
        }
        for(int i=s;i<=n;i++){
            g[i]=0;
        }
       for(int i=1;i<=dis[n];i++){
            pos[i]=0;
        }
    }
        cout<<ans<<'\n';
    }
    return 0;
}
