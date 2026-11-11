#include<bits/stdc++.h>
using namespace std;
int n,m,f;
int a[100001],b[100001],sum[100001];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    for(int i=1;i<=100000;i++){
        b[i]=-1;
    }
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            for(int k=j;k<=n;k++){
                b[k]=-1;
            }
            for(int k=1;k<=n;k++){
                if(a[j]==b[k]) f=1;
                if(f==1) b[k]=-1;
            }
            b[j]=a[j];
            f=0;
        }
        for(int k=1;k<=n;k++){
            if(b[k]!=-1){
                sum[b[k]]++;
            }
        }
        for(int i=1;i<=m;i++){
            cout<<sum[i]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
