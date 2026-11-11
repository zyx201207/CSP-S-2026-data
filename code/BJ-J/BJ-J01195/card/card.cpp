#include<bits/stdc++.h>
using namespace std;
const int N1=5e5+5,N2=3e5+5;
int n,m,a[N1],vst[N2],cnt[N1],s[N1],top=0;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        top=0;
        for(int j=1;j<=m;j++)vst[j]=0;
        for(int j=i;j<=n;j++){
            if(!vst[a[j]]){
                vst[a[j]]=1;
                s[++top]=a[j];
            }
            else{
                while(s[top]!=a[j]){
                    vst[s[top]]=0;
                    top--;
                }
            }
        }
        for(int i=1;i<=m;i++)if(vst[i])cnt[i]++;
    }
    for(int i=1;i<=m;i++)cout<<cnt[i]<<" ";
    return 0;
}
