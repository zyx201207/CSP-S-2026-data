#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","r",stdin);
    int n,m,a[500005],b[300005];
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(a[n]==a[n-1]){
            for(int i=1;i<=m;i++){
                    if(i==a[n]){
                 cout<<n<<" ";
                    }else{
                    cout<<0<<" ";
                    }
            }
    }else if(m==2){
        int al[55];
        for(int j=1;j<=n;j++){
        for(int i=j;i<=n;i++){
            al[i+j*2]=a[i];
            if(a[i]==al[i+j*2-1]||a[i]==al[i+j*2-2]){
                memset(al,0,sizeof al);
                al[i+j*2]=a[i];
            }
        }
        for(int k=1;k<=25;k++){
            if(al[k]>0){
                b[al[k]]++;
            }
        }
        }
        for(int i=1;i<=n;i++){
            cout<<b[i]<<" ";
        }
        }else{
    for(int i=1;i<=n;i++){
            int dp[300005];
            int ii=n;
            int p=a[n];
        while(ii>=i&&dp[p]==0){
            dp[a[ii]]=1;
            b[a[ii]]++;
            ii--;
            p=a[ii];
        }
    }
    for(int i=1;i<=m;i++){
        cout<<b[i]<<" ";
    }
    }
    return 0;
}