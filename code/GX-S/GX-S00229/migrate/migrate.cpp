#include<bits/stdc++.h>
using namespace std;
int c,t,a[2000005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        int n,d,x[2000005],ans=0;
        a[1]=1;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
            for(int j=1;j<i;j++){
                if(x[i]-x[j]<=d && d/(x[i]-x[j])<2){
                    a[i]+=a[j];
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(a[i]==2){
                ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
