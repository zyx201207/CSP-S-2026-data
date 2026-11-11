#include<bits/stdc++.h>
using namespace std;
    int n,m;
    int a[500050],ans[300005]={0};
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int s[500050];
    for(int i=1;i<=n;i++){
        for(int k=1;k<=m;k++)s[k]=0;
        for(int j=i;j<=n;j++){
            s[j]=a[j];
            for(int k=i;k<j;k++){
                if(s[j]==s[k])for(int t=k+1;t<=j;t++)s[t]=0;
            }
        }
        for(int j=i;j<=n;j++){
            if(s[j]!=0)ans[s[j]]++;
        }
    }
    for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
    return 0;
}
