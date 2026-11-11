#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000000],b[1000000],pos,findd[1000000],cnt[1000000];
int main(){
    freopen("card.in","r",stdin);freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++){
        pos=0;
        for(int j=i;j<n;j++){
            if(findd[a[j]]){
                while(pos&&a[j]!=b[pos])findd[b[pos--]]=0;
            }b[pos++]=a[j];findd[a[j]]=1;
        }for(int j=1;j<=m;j++)findd[j]=0;
        for(int j=0;j<pos;j++){
            cnt[b[j]]++;
        }
    }for(int i=1;i<=m;i++){
        cout<<cnt[i]<<' ';
    }return 0;
}
