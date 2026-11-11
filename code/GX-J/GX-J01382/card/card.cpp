#include<bits/stdc++.h>
using namespace std;
int a[200005],b[200005]={0},c[200005]={0};
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
            cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            for(int x=1;x<=n;x++){
                if(c[x]==a[j]){
                    for(int q=1;q<=n;q++){
                        c[q]=0;
                    }
                    c[x]=a[j];
                }else{
                    c[x]=a[j];
                }
            }
        }
        for(int j=1;j<=m;j++){
            b[c[j]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<b[i]<<" ";
    }
    return 0;
}
