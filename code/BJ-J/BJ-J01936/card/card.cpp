#include<bits/stdc++.h>
using namespace std;
int a[500005];
int ans[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m>3000){
        for(int i=1;i<=n;i++){
            ans[a[i]]=i;
        }
        for(int j=1;j<=m;j++)cout<<ans[j]<<" ";
        return 0;
    }
    for(int i=1;i<=n;i++){
        int loc[500005]={0};
        for(int j=i;j<=n;j++){
            if(loc[a[j]]==0){
                loc[a[j]]=j;
                //cout<<a[j]<<j<<endl;
            }else{
                for(int k=loc[a[j]];k<=j;k++)loc[a[k]]=0;
                loc[a[j]]=j;

            }
            //cout<<loc[3]<<endl;
        }
        //cout<<loc[2]<<endl;
        for(int j=1;j<=m;j++){
            if(loc[j]!=0)ans[j]++;
        }
    }
    for(int j=1;j<=m;j++)cout<<ans[j]<<" ";
    return 0;
}
