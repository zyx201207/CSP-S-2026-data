#include<iostream>
using namespace std;
const int maxn=2020000;
int c,T,n;
long long d,x[maxn];
int lmin[maxn],rmax[maxn],dpl[maxn],dpl2[maxn],dpr[maxn],dpr2[maxn];
long long ans;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>T;
    while(T--){
        cin>>n>>d;ans=0;
        for(int i=1;i<=n;i++)cin>>x[i];
        for(int i=1;i<=n;i++){
            int l=1,r=i;
            while(l<r){
                int mid=l+r>>1;
                if(x[i]-x[mid]<=d)r=mid;
                else l=mid+1;
            }
            lmin[i]=l;
            l=i,r=n;
            while(l<r){
                int mid=l+r+1>>1;
                if(x[mid]-x[i]<=d)l=mid;
                else r=mid-1;
            }
            rmax[i]=l;
        }
        for(int i=1;i<=n;i++){
            if(lmin[i]==i){dpl[i]=1;continue;}
            int l=i,r=n;
            while(l<r){
                int mid=l+r+1>>1;
                if(lmin[mid]==lmin[i])l=mid;
                else r=mid-1;
            }
            dpl[l]=dpl[lmin[l]]+l-lmin[l];
            for(int j=i;j<l;j++)dpl2[j]=0,dpl[j]=1;
            int ll=lmin[l],rr=l-1;
            while(ll<rr){
                int mid=ll+rr+1>>1;
                if(x[l+1]-x[mid]<=d)rr=mid-1;
                else ll=mid;
            }
            dpl[l]-=l-ll-1;
            if(i==l)dpl2[l]=lmin[l+1]-lmin[l];
            else dpl2[l]=dpl[l]-1;
            i=l;
        }
        for(int i=n;i>=1;i--){
            if(rmax[i]==i){dpr[i]=1;continue;}
            int l=1,r=i;
            while(l<r){
                int mid=l+r>>1;
                if(rmax[mid]==rmax[i])r=mid;
                else l=mid+1;
            }
            dpr[l]=dpr[rmax[l]]+rmax[l]-l;
            for(int j=l+1;j<=i;j++)dpr2[j]=0,dpr[j]=1;
            int ll=l+1,rr=rmax[l];
            while(ll<rr){
                int mid=ll+rr>>1;
                if(x[mid]-x[r-1]<=d)ll=mid+1;
                else rr=mid;
            }
            dpr[l]-=ll-l-1;
            if(i==l)dpr2[l]=rmax[l]-rmax[l-1];
            else dpr2[l]=dpr[l]-1;
            i=l;
        }
        for(int i=2;i<=n-2;i++)if(lmin[i+1]<i&&lmin[i+2]>lmin[i+1]&&rmax[i]>i+1&&rmax[i-1]<rmax[i]&&x[rmax[i]]-x[lmin[i+1]]>d)
            ans+=1ll*dpl2[i+1]*dpr2[i];
        cout<<ans<<"\n";
    }
    return 0;
}