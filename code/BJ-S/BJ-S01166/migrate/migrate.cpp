# include<bits/stdc++.h>
using namespace std;
int c,t;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        int ans=0;
        int n;long long d;
        cin>>n>>d;
        long long x[n+10];
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        sort(x+1,x+1+n);
        int L=1,R=4;
        while(L<R&&R<=n){
            long long lv=x[L]+d,rv=x[R]-d;
            int l=1,r=n,ls,rs;
            while(l<=r){
                int mid=(l+r)>>1;
                if(lv==x[mid]){
                    r=mid;break;
                }else if(lv>x[mid]){
                    l=mid+1;
                }else{
                    r=mid-1;
                }
            }ls=r;
            l=1,r=n;
            while(l<=r){
                int mid=(l+r)>>1;
                if(rv==x[mid]){
                    l=mid;break;
                }else if(rv>x[mid]){
                    l=mid+1;
                }else{
                    r=mid-1;
                }
            }
            rs=l;
            if(ls-rs==1){
                long long cntl=1,cntr=1;
                while(x[L+1]+d<x[ls+1]&&L+1<R)L++,cntl++;
                while(x[rs]>=x[R+1]-d&&R+1<=n)R++,cntr++;
                ans+=cntl*cntr;
                if(L+1<R)L++;
                else R++;
            }else if(ls>rs){
                R++;
            }else{
                L++;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
