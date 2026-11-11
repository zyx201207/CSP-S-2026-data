#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,a[100005],cnt[100005]={0},cnts=0,me[100005]={0},c[100005]={0};
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cnt[a[i]]++;
    }for(int i=1;i<=n;i++){
        if(cnt[i]>1)cnts++;
    }for(int o=1;o<=n;o++){
        for(int i=o;i<=n;i++){
            me[a[i]]++;
            int l=0,j=i;
            if(me[a[i]]==2){
                for(;a[j]!=a[i];){
                    j--;
                }
            }for(int k=i;k<j;k++){
                a[k]=-1;
            }
        }for(int i=1;i<=n-o+1;i++){
            if(a[i]==-1)continue;
            c[a[i]]++;
        }
    }for(int i=1;i<=m;i++)cout<<c[i]<<'\n';
    return 0;
}