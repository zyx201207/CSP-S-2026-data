#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=5e5+10;
int a[N];
int ans[N],f[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(i==1){
            cnt++;
            ans[a[i]]++;
            f[i]=a[i];
            continue;
        }
        int t=0;
        int od=cnt;
        for(int j=1;j<=cnt;j++){
            if(f[j]==a[i]){
                t=j;
                for(int k=j;k<=od;k++){
                    cnt--;
                }
            }
        }
        if(t==0){
            f[i]=a[i];
            cnt++;
            for(int j=1;j<=cnt;j++){
                if(f[j]!=0){
                    ans[f[j]]++;
                }
            }
        }else{
            f[t]=a[t];
            cnt++;
            for(int j=1;j<=cnt;j++){
                if(f[j]!=0){
                    ans[f[j]]++;
                }
            }
        }
    }
    for(int i=1;i<=m;i++){
        printf("%d ",ans[i]);
    }
    return 0;
}
