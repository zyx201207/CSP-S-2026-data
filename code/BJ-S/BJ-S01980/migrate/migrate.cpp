#include<bits/stdc++.h>
using namespace std;
const int N=5010+10;
int C,T,n,f[N],lst[N];
long long d,a[N],o[N];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&C,&T);
    while(T--){
        scanf("%d%lld",&n,&d);
        for(int i=1;i<=n;i++){
            scanf("%lld",&a[i]);
        }
        for(int i=1;i<=n;i++){
            int l=1,r=i;
            while(l<=r){
                int mid=l+r>>1;
                if(a[i]-a[mid]>d)l=mid+1;
                else r=mid-1;
            }
            lst[i]=l;
        }
        long long ans=0;
        for(int s=1;s<=n;s++){
            memset(f,0x3f,sizeof(f));
            memset(o,0,sizeof(o));
            f[s]=0;
            o[s]=1;
            for(int i=s+1;i<=n;i++){
                f[i]=f[max(s,lst[i])]+1;
                if(lst[i]!=i)o[i]=o[max(s,lst[i])];
                //if(s==1&&i==4){
                    //cout<<f[2]<<' '<<f[3]<<' '<<lst[i]<<"??"<<endl;
               // }
                if(lst[i]>=s&&(lst[i]+1<i&&f[lst[i]]==f[lst[i]+1])&&(lst[i]+2>=i||f[lst[i]+2]>f[lst[i]])){
                    if(o[lst[i]]+o[lst[i]+1]<=2)o[i]+=o[lst[i]+1];
                    else o[i]=3;
                }
                if(lst[i]>=s&&(lst[i]+1<i&&f[lst[i]]==f[lst[i]+1])&&(lst[i]+2<i&&f[lst[i]+2]==f[lst[i]])){
                    o[i]=3;
                }
            }
          //  cout<<"!!"<<endl;
            for(int i=s+1;i<=n;i++){
              //      cout<<o[i]<<' ';
                if(o[i]==2)ans++;
            }
          //  cout<<endl;
        }
        printf("%lld\n",ans);
    }
    return 0;
}