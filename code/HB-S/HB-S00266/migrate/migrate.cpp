#include<bits/stdc++.h>
using namespace std;
int c,t;
long long x[2000200],dpmin[2000200],dpcnt[2000200];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        int n,d;
        cin>>n>>d;
        int sum=0;
        for(int i=1;i<=n;i++) cin>>x[i];
        for(int i=1;i<=n-2;i++){
            for(int j=i+2;j<=n;j++){
                for(int k=i;k<=j;k++) dpmin[k]=j-i+1,dpcnt[k]=0;
                dpmin[i]=0;
                for(int k=i+1;k<=j;k++){
                    int l=k-1;
                    while(l>=i&&x[k]-x[l]<=d){
                        if(dpmin[l]+1<dpmin[k]){
                            dpmin[k]=dpmin[l]+1;
                            dpcnt[k]=1;
                        }else if(dpmin[l]+1==dpmin[k]){
                            dpcnt[k]++;
                        }
                        l--;
                    }
                }
                if(dpcnt[j]==2) sum++;
            }
        }
        cout<<sum<<'\n';
    }
    return 0;
}
