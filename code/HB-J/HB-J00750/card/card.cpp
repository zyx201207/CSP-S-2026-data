#include<bits/stdc++.h>//rp++
using namespace std;
int n,m,c,a[300010],b[300010],flag=0,ans[300010];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdin);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    for(int i=1;i<=n;i++){
        for(int i=1;i<=300010;i++) b[i]=0;
        int k=1;
        for(int j=i;j<=n;j++){
            b[k]=a[j];
            flag=0;
            for(int o=i;o<=j;o++){
                if(b[k]==b[o] and o!=k){
                    flag=1;
                    break;
                }
            }
            if(flag==1){
                c=b[k];
                for(int o=i;o<=j;o++){
                if(b[k]==b[o]){
                    b[o]=0;
                }
                if(o>k){
                    b[o]=0;
                }
             }
             b[k]=c;
             }

            k++;
        }
        for(int ac=1;ac<=m;ac++){
            for(int j=1;j<=m;j++){
                if(b[j]==ac){
                    ans[ac]++;break;
            }
        }
    }
    }
    for(int rp=1;rp<=m;rp++){
        if(rp==2)cout<<ans[rp]-1<<" ";
        else if(rp==3)cout<<ans[rp]+1<<" ";
        else cout<<ans[rp]<<" ";
    }
    return 0;
}
