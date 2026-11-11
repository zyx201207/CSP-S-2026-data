#include<bits/stdc++.h>
using namespace std;
int a[500005];
int u[500005];
int t[300005];
int d[300005];
int n,m;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<=300000;i++){
        t[i]=-1;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int i=1;
    while(n--){
        int k=0;
        for(int j=i;j<=n;j++){
            k++;
            t[u[k]]=-1;
            if(t[a[j]]==-1){
                u[k]=a[j];
                t[a[j]]=k;
            }else{
                k=t[a[j]];
            }
            
        }
        for(int j=1;j<=k;j++){
            d[u[j]]++;
        }
        for(int j=0;j<=n;j++){
            t[j]=-1;
            u[j]=0;
        }
        i++;
    }
    for(int j=1;d[j]!=0;j++){
        cout<<d[j]<<" ";
    }
    return 0;
}
