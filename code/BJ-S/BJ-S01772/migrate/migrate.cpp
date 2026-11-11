#include<bits/stdc++.h>
using namespace std;
    long long c,t,n,d,x[2000005],book[2000005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        long long maxx=-1e10,minn=1e10;
        long long ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
            x[i]+=1000000;
            book[x[i]]=1;
            maxx=max(maxx,x[i]);
            minn=min(minn,x[i]);
        }

        for(int i=minn;i<maxx-d;i++){
            for(int j=i+d+1;j<=maxx;j++){
                if(!book[j])continue;
                long long l=j-d,r=i+d,num=0;
                while(l>r){
                    l-=d;
                    r+=d;
                }
                for(int k=l;k<=r;k++){
                    num+=book[k];
                }
                if(num==2){
                    ans++;
                    //cout<<i<<' '<<j<<endl;
                }
            }
        }
        cout<<ans<<endl;
        for(long long i=1;i<=n;i++){
            book[x[i]]=0;
            x[i]=0;
        }
    }

return 0;}
