
#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
const int M=3e5+10;
int n,m,a[N],my_sum[M],my_dui[M],my_xia[M];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        memset(my_dui,0,sizeof(my_dui));
        for(int j=i;j<=n;j++){
            if(my_dui[a[j]]!=0){
                for(int k=my_xia[a[j]];k<=m;k++){
                    my_dui[k]=0;
                }
            }
            my_dui[a[j]]=1;
            my_xia[a[j]]=i;
        }
        for(int j=1;j<=m;j++){
            if(my_dui[j]==1){
                my_sum[j]++;
            }
        }
    }
    for(int j=1;j<=m;j++){
        cout<<my_sum[j]<<" ";
    }
    return 0;
}
