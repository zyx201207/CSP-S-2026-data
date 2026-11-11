#include<bits/stdc++.h>
using namespace std;
int n,m,a[500007],d[300007],cnt[300007];
bool f[300007],flag[500007];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n>500){
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                if(a[j]!=a[j-1]){
                    cnt[a[j]]++;
                }
            }
        }
        for(int i=1;i<=m;i++){
            cout<<cnt[i]<<' ';
        }
        return 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(f[a[j]]){
                for(int k=d[a[j]]+1;k<=j;k++){
                    if(!flag[k]){
                        cnt[a[k]]--;
                        flag[k]=true;
                    }
                }
            }
            else{
                f[a[j]]=true;
            }
            cnt[a[j]]++;
            d[a[j]]=j;
        }
        for(int j=1;j<=500;j++){
            f[j]=false;
        }
        for(int j=1;j<=500;j++){
            flag[j]=false;
        }
        for(int j=1;j<=n;j++){
            d[j]=0;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<' ';
    }
    return 0;
}
