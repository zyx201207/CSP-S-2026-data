#include<bits/stdc++.h>
using namespace std;
char inf[1<<20],*p1=inf,*p2=inf;
#define getchar() (p1==p2?(p2=inf+fread(p1=inf,1,1<<20,stdin),(p1==p2?EOF:*p1++)):*p1++)
inline long long read(){
    long long x=0,w=1,ch=getchar();
    while(ch<'0'||ch>'9')w=ch=='-'?-1:1,ch=getchar();
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x*w;
}
const int N=3e6;
int d[N];
long long a[N];
pair<int,int> dis[N];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int C=read(),t=read();
    while(t--){
        int n=read();
        long long k=read();
        for(int i=0;i<n;i++)a[i]=read();
        long long ans=0;
        if(n<=2){
            puts("0");
            continue;
        }
        if(C==11||C==12){
            k/=(a[1]-a[0]);
            for(int i=0;i<n;i++)
                if(k>1&&i+k+k-1<n)ans++;
            printf("%lld\n",ans);
            continue;
        }
        if(C==13||C==14){
            //for(int i=0;i<n;i++)b[i]=0;
            for(int i=n-1,r=n-1,l=n-1;i>=0;i--){
                while(r>i&&a[r]-a[i]>k)r--;
                //while(l>0&&a[i]-a[l-1]<=k)l--;
                //b[l]+=b[i]+1,c[i]=i<r?c[r]:0,e[i]=l,ans+=c[i];
                d[i]=r;
                if(i<r-1&&d[r-1]>r){
                    long long tmp=0;
                    ans+=d[r-1]-max(d[r-2],r);
                    //if(d[r]==d[r-1]&&d[r]>d[r-2])
                        //tmp+=b[d[r]];
                    //ans+=tmp,c[i]+=tmp*(r-1>i&&e[r-1]==i);
                }
                //cout<<l<<" "<<r<<" "<<b[i]<<" "<<c[i]<<" "<<ans<<"\n";
            }
            printf("%lld\n",ans);
            continue;
        }
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++)dis[j]={1000000000,-1};
            dis[i]={0,1};
            for(int j=i;j<n;j++)
                if(dis[j].second>0){
                    for(int l=j+1;l<n&&a[l]-a[j]<=k;l++)
                        if(dis[j].first+1<dis[l].first)
                            dis[l]=dis[j],dis[l].first++;
                        else if(dis[j].first+1==dis[l].first)
                            dis[l].second=min(3,dis[l].second+dis[j].second);
                    ans+=dis[j].second==2;
                }
        }
        printf("%lld\n",ans);
    }
    return 0;
}

