#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
    long long a[200005];
    long long b[200005][35];
    long long sum[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int j=0;
    for(int i=1;i<=n;i++){
        while(a[i]){
            if(a[i]&1==1){
                b[i][j]=1;
                j++;
                a[i]>>=1;
            }else{
                b[i][j]=0;
                j++;
                a[i]>>=1;

            }
        }
        j=0;
    }
    /*for(int i=1;i<=n;i++){
        for(int k=0;k<=30;k++){
            cout<<b[i][k];
        }
        cout<<"\n";
    }*/
    long long two[35];
    long long t=1;
    for(int i=0;i<=30;i++){
        two[i]=t;
        t*=2;
    }
    for(int k=0;k<=30;k++){
        for(int i=1;i<=n;i++){
            if(b[i][k]==1)
                sum[k]++;
        }
    }
    /*for(int i=0;i<=30;i++){
        cout<<sum[i]<<" ";
    }*/

    long long ma=0,ans=0,c=0;
    for(int i=1;i<=m;i++){
         for(int k=0;k<=30;k++){
            if(sum[k]>=ma){
                c=k;
                ma=sum[k];
            }
        }
         ans+=two[c];
         sum[c]=0;
         ma=0;
    }


cout<<ans;





    return 0;
}
