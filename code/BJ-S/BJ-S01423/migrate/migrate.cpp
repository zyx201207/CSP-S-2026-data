#include<bits/stdc++.h>
using namespace std;
const int N=5005; 
#define int long long
int c,t,n,d,a[2000005],p[2000005],f[N],g[N],ans,st1[N][14],st2[N][14];
pair<int,int> ask(int l,int r){
    int k=r-l+1,x=1e9,y=0;
    for(int i=13;i>=0;i--)
        if(k>>i&1){
            if(st1[l][i]<x)x=st1[l][i],y=st2[l][i];
            else if(st1[l][i]==x)y+=st2[l][i];
            l+=1<<i,k-=1<<i;
        }
    return make_pair(x,y);
}signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    if(c<=10){
        while(t--){
            cin>>n>>d,ans=0,p[1]=1;
            for(int i=1;i<=n;i++){
                cin>>a[i],p[i]=p[i-1];
                if(i==1)p[i]=1;
                while(a[i]-a[p[i]]>d)p[i]++;
            }for(int i=1;i<n;i++){f[i]=0,g[i]=1;
                for(int j=0;i+(1<<j)-1<=n;j++)
                    st1[i][j]=0,st2[i][j]=1;
                for(int j=i+1;j<=n;j++){
                    auto P=ask(max(p[j],i),j-1);
                    f[j]=P.first+1,g[j]=P.second;
                    if(g[j]==2)ans++;
                    st1[j][0]=f[j],st2[j][0]=g[j];
                    for(int k=1;j-(1<<k)+1>=i;k++)
                        if(st1[j-(1<<k)+1][k-1]<st1[j-(1<<k-1)+1][k-1])
                            st1[j-(1<<k)+1][k]=st1[j-(1<<k)+1][k-1],
                            st2[j-(1<<k)+1][k]=st2[j-(1<<k)+1][k-1];
                        else if(st1[j-(1<<k)+1][k-1]==st1[j-(1<<k-1)+1][k-1])
                            st1[j-(1<<k)+1][k]=st1[j-(1<<k)+1][k-1],
                            st2[j-(1<<k)+1][k]=st2[j-(1<<k)+1][k-1]+st2[j-(1<<k-1)+1][k-1];
                        else st1[j-(1<<k)+1][k]=st1[j-(1<<k-1)+1][k-1],st2[j-(1<<k)+1][k]=st2[j-(1<<k-1)+1][k-1];
                }
            }cout<<ans<<"\n";
        }
    }else if(c<=12){
        while(t--){
            cin>>n>>d,ans=0;
            for(int i=1;i<=n;i++)cin>>a[i];
            int k=d/(a[2]-a[1]);
            if(k<=1){cout<<"0\n";continue;}
            for(int i=1;i<=n;i++)
                if(i+2*k-1<=n)
                    ans++;
            cout<<ans<<"\n";
        }
    }else{
        while(t--){
            cin>>n>>d,ans=0,p[1]=1;
            for(int i=1;i<=n;i++){
                cin>>a[i],p[i]=p[i-1];
                if(i==1)p[i]=1;
                while(a[i]-a[p[i]]>d)p[i]++;
            }for(int i=1;i<=n;i++)
                ans+=p[p[i]+1]-p[p[i]]-1;
            cout<<ans<<"\n";
        }
    }
}