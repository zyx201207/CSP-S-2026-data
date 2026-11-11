#include<bits/stdc++.h>

int n,m,a[500005],cnt[500005];

void work(int x){
    int g[300005]={},b[500005]={};
    int j=1;
    for(int i=x;i<=n;i++){
        if(g[a[i]]==0){
            g[a[i]]=j;
            b[j]=a[i];
        }else{
            for(int q=g[a[i]]+1;q<j;q++){
                g[b[q]]=0;
            }
            j=g[a[i]];
        }j++;
    }
    for(int i=1;i<j;i++){
        cnt[b[i]]++;
    }

}

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    std::cin>>n>>m;
    for(int i=1;i<=n;i++){
        std::cin>>a[i];
    }

    for(int i=1;i<=n;i++){
        work(i);
    }
    for(int i=1;i<=m;i++){
        std::cout<<cnt[i]<<' ';
    }

return 0;
}
