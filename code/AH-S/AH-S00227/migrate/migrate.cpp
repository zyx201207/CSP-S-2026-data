#include<bits/stdc++.h>
using namespace std;
long long T,c,n,d,x[200005],f[200005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>T;
    while(T--){
        cin>>n>>d;
        for(int i=1;i<=2;i++){
            scanf("%lld",&x[i]);
        }
        int a;
        for(int i=3;i<=n;i++)scanf("%d",&a);
        long long ans;
        if(c==11||c==0){
            int k=x[2]-x[1];
            if(d*1.0/k<=1)ans=0;
            else{
                for(int i=p+1;i<2*n;i++){
                    ans+=n-d/k-1;
                }
            }
        }else{
            ans=n/2;
        }
        if(ans<=0)ans=0;
        printf("%lld\n",ans);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

