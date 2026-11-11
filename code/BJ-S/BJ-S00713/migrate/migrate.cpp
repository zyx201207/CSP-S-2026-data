#include<bits/stdc++.h>
using namespace std;
long long n,d,c,T,x[2000005];
struct node{
    long long l,num;
}f[2000005];
void solve(long long st){
    for(int i=st+1;i<=n;i++){
        for(int j=st;j<i;j++){
            if(x[i]-x[j]>d)continue;
            if(f[j].l+1<f[i].l){
                f[i].l=f[j].l+1;
                f[i].num=f[j].num;
            }else if(f[j].l+1==f[i].l){
                f[i].num+=f[j].num;
            }
        }
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);/*zhushi!!!!!!!!!!!!!*/
    scanf("%lld%lld",&c,&T);
    while(T--){
        scanf("%lld%lld",&n,&d);
        long long ans=0;
        for(int i=1;i<=n;i++){
            scanf("%lld",&x[i]);
        }
        if(n>5000){
            long long id=0;
            for(int i=1;i<=n;i++){
                if(x[i]-x[1]<=d&&x[n]-x[i]<=d){
                    id=i;
                }
            }
            long long l=1,r=1;
            for(int i=id+1;i<=n;i++){
                while(x[i]-x[l]>d)l++;
                l--;
                ans+=(i-l-1==2)?1:0;
            }
        }else{

        for(int i=1;i<n;i++){
            for(int j=1;j<=n;j++)f[j].l=1e15,f[j].num=0;
            f[i].l=0;
            f[i].num=1;
            solve(i);
            for(int j=i;j<=n;j++){
                    //cout<<f[j].num<<" ";
                if(f[j].num==2)ans++;
            }//cout<<endl;
        }
        }
        printf("%lld\n",ans);
    }




    return 0;
}
