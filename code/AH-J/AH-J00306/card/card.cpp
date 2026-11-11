#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],ans[300010],c[500010],ed,flag;

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        memset(c,0,sizeof c);ed=0;
        for(int j=i;j<=n;j++){
            int q=min(ed,j-1);
            for(int z=1;z<=q;z++){
                if(c[z]==a[j]){
                    flag=1;
                    ed=z;
                    c[ed]=a[j];
                    break;
                }
            }
            if(flag==0){
                ed++;c[ed]=a[j];
            }
            flag=0;
        }
        for(int j=1;j<=ed;j++){
            ans[c[j]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
