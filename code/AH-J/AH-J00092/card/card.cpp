#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],cnt[5005],hasp[50005];
void f(int l){
    for(int i=l;i<=n;i++){
        int k=100000000;
        for(int j=i-1;j>=l;j--){
            if(a[j]==a[i]&&hasp[j]==1){
                k=j;
                break;
            }
        }
        for(int j=k;j<=i;j++){
            hasp[j]=0;
        }
    }
    return;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            hasp[j]=1;
        }
        f(i);
        int f[5005];
        for(int j=1;j<=m;j++){
            f[j]=0;
        }
        for(int i=1;i<=m;i++){
            if(hasp[i]==1&&f[a[i]]==0){
                f[a[i]]=1;
                cnt[a[i]]++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<" ";
    }
}
