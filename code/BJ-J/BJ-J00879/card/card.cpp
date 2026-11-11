#include<bits/stdc++.h>
using namespace std;
int a[500005],ans[500005]={},now[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int num=1;
        for(int j=i;j<=n;j++){
            now[num]=a[j];
            for(int k=1;k<num;k++){
                if(a[j]==now[k]&&a[j]!=0){
                    for(int l=k;l<num;l++){
                        now[l]=0;

                    }
                }
            }
            num++;
        }
        for(int k=0;k<num;k++){
            ans[now[k]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}
