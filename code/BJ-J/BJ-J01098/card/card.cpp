#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
int n,m,a[maxn],b[maxn],cnt[maxn];
int find(int id,int num){
    for(int i=id;i>=1;i--){
        if(b[i]==num){
            return i;
        }
    }
    return 0;
}
void work(int i){
    for(int j=1;j<=n;j++){
        b[j]=0;
    }
    int step=0;
    for(int j=i;j<=n;j++){
        int k=find(step,a[j]);
        if(k){
            step=k-1;
        }
        b[++step]=a[j];
    }
    //for(int j=1;j<=step;j++){
    //    cout<<b[j]<<" ";
    //}
    //cout<<"\n";
    for(int j=1;j<=step;j++){
        cnt[b[j]]++;
    }
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        work(i);
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<" ";
    }
    return 0;
}