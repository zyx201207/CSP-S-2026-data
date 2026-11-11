#include <bits/stdc++.h>
/*
gameplay

4 3
1 2 1 3

run i: from i to n-1
(use o(n3) but no 2e3

 1 2 3 4 5 2 3 4 6

 idk i choose to quit
*/
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int m,n,a[200005];
    int i,j,k,ii;
    int s[200005]={};
    int ans[200005]={};
    cin>>n>>m;
    for(i=1;i<=n;++i)cin>>a[i];
    for(i=1;i<=n;++i){//n runs
        for(j=i;j<=n;++j){//run i
            s[j]=a[j];}

        for(j=n;j>=i;--j){
            for(k=j;k>=i;--k){
                if(s[j]=s[k]){
                    for(ii=k;ii<j;++ii)s[ii]=0;
                }
            }
        }


        for(j=i;j<=n;++j){
            ans[s[j]]++;
        }

        //s={};//clear game
    }

    for(i=1;i<=m;++i)cout<<ans[i]<<' ';
    return 0;
}

