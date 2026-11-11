#include<bits/stdc++.h>
using namespace std;
int n,m,ans,a[200001],flag[200001];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)flag[i]=1;
    for(int i=29;i>=0;i--){
        int cnt=0;
        for(int j=1;j<=n;j++)if((flag[j]==1)&&(((a[j]>>i)&1)==1))cnt++;
        if(cnt>=m){
            ans+=(1<<i);
            for(int j=1;j<=n;j++){
                if((flag[j]==1)&&(((a[j]>>i)&1)==1))flag[j]=1;
                else flag[j]=0;
            }
        }
    }
    cout<<ans;
    return 0;
}