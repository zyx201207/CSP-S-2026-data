#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[300005],f[500005],sum,s[500005];
map<int,int>ma;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)f[j]=0;
        ma.clear();
        for(int j=i;j<=n;j++){
            if(ma.find(a[j])!=ma.end()){
                for(int k=ma[a[j]];k<j;k++){
                    f[k]=1;
                    if(ma[a[k]]>=ma[a[j]])ma[a[k]]=0;
                }
            }
            ma[a[j]]=j;
        }
        for(int j=i;j<=n;j++){
            if(f[j]==0)b[a[j]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<b[i]<<" ";
    }
    return 0;
}
