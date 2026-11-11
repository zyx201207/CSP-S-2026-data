#include <bits/stdc++.h>
using namespace std;
long long n,d,a[2000005],as=0,ans=0,cc=0;
void dfs(int q,int z,int l){
    if(q==z){
        as=min(as,l*1LL);
        //cout<<q<<" "<<z<<" "<<l<<"\n";
        return;
    }for (int i=q+1;i<=z;i++){
        if (a[q]+d>=a[i]){
                //cout<<i<<" "<<z<<" "<<l+1<<"\n";
            dfs(i,z,l+1);


        }
    }return;
}


void qiu(int q,int z,int l){
    if(q==z){
        if (l==as)ans++;
        //cout<<as<<" "<<q<<" "<<z<<" "<<l<<"\n";
        return;
    }for (int i=q+1;i<=z;i++){
        if (a[q]+d>=a[i]){
                //cout<<i<<" "<<z<<" "<<l+1<<"\n";
            qiu(i,z,l+1);


        }
    }return;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for (int i=1;i<=n;i++){
            cin>>a[i];
        }
        //dfs(1,4,0);
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                as=1e9;
                ans=0;
                dfs(i,j,0);
                qiu(i,j,0);
                //cout<<ans<<" ";
                if (ans==2){
                        cc++;
                        //cout<<i<<j;
                }
                //cout<<"\n";
                //cout<<i<<" "<<j<<" "<<as<<"\n";
            }
        }
        cout<<cc<<"\n";
    }
    return 0;
}