#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int p[500005],a[300005],b[300005];
    for(int i=1;i<=n;i++){
        cin>>p[i];
    }
    for(int i=1;i<=n;i++){
        memset(a,0,sizeof a);
        int mu=i;
        for(int j=i;j<=n;j++){
            if(a[p[i]]!=0&&a[p[i]]<mu){
                mu=a[p[i]];
            }else{
                a[p[i]]=mu;
            }
            mu++;
        }
        for(int j=i;j<=n;j++){
            if(a[j]<=mu){
                b[a[j]]++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<b[i];
    }
    return 0;
}