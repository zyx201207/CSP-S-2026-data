#include<iostream>
#include<cstdio>
using namespace std;
int n,m,a[500005],am[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        int pos=i,pa[500005]={},pam[300005]={},pp[500005]={},npam[500005]={};
        for(int j=i;j<=n;j++){
            if(pam[a[j]]==0)pa[pos]=a[j],pam[a[j]]=1,pp[a[j]]=pos,pos++;
            else{
                for(int k=pp[a[j]]+1;k<=pos;k++)pam[pa[k]]=0,pa[k]=0;
                pos=pp[a[j]]+1;
            }
        }
        for(int k=i;k<=n;k++)npam[pa[k]]++;
        for(int j=1;j<=m;j++)am[j]+=npam[j];
    }
    for(int i=1;i<=m;i++)cout<<am[i]<<" ";
    return 0;
}