#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m,a[N],t[N],x[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        t[a[i]]++;
    }
    for(int i=1;i<=n;i++){
        int l=i;
        while(t[a[l]]==1&&l<=n)l++;
        if(l>n){
            for(int j=i;j<=n;j++)x[a[j]]++;
            t[a[i]]--;
            continue;
        }
        while(l<=n){
            for(int j=n;j>l;j--){
                if(a[j]==a[l]){l=j;break;}
            }
            x[a[l++]]++;
        }
        x[a[l]]++;
        t[a[i]]--;
    }
    for(int i=1;i<=m;i++){
        printf("%d ",x[i]);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
