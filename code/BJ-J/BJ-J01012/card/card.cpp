#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
const int M=3e5+10;
int n,m,a[N],ans[M],b[N];
struct node{
    int vis,pl;
}flag[M];

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;

    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){

            if(flag[a[j]].vis){
                for(int k=flag[a[j]].pl+1;k<=n;k++){
                    b[k]=0;
                }

            }
            b[j]=a[j];
            flag[a[j]].vis=1;
            flag[a[j]].pl=j;

        }

        stable_sort(b+1,b+1+n);
        for(int j=1;j<=m;j++){
            if(binary_search(b+1,b+1+n,j))ans[j]++;
        }
        memset(b,0,sizeof b);
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}


