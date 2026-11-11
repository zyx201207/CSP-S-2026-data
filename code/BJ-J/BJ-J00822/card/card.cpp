#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,a[500010],c[500010],s[500010];
    cin>>n>>m;
    int b[m+10];
    for(int i=1;i<=n;i++){
        cin>>a[i];
        c[i]=0;
    }
    for(int i=1;i<=m;i++){
        b[i]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(s[j]!=1){
                s[j]=1;
            }
        }
        for(int j=i;j<=n;j++){
            for(int y=1;y<=n;j++){
                if(c[y]==0){
                    c[y]=a[j];
                    break;
                }
                if(a[j]==c[y]){
                    for(int r=y;r<=n;r++){
                        if(a[r]!=0){
                            a[r]=0;
                        }
                        else{
                            break;
                        }
                    }
                }
            }
        }
        for(int j=1;j<=n;j++){
            if(c[i]!=0){
                if(s[c[i]]==1){
                    b[c[i]]++;
                    s[c[i]]=0;
                }
            }
            else{
                break;
            }
        }
    }
    for(int i=1;i<=m;i++){
        if(b[m]!=0){
            cout<<b[m]<<" ";
        }
    }
    return 0;
}
