#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],flag=1,b[500005],ans[200005],w[200005],la[500005],dd=1;
struct node{
    int st,en;
}d[500005];
void solveA(){
    int k;
    for(int i=1;i<=n;i++){
        k=2;
        memset(b,0,sizeof(b));
        b[1]=a[i];
        for(int j=i+1;j<=n;j++){
            if(a[j]!=a[j-1]){
                b[k]=a[j];
                k++;
            }
        }
        for(int j=1;j<k;j++){
            ans[b[j]]++;
        }
        if(i==n){
            for(int j=1;j<=m;j++){
                cout<<ans[j]<<" ";
            }
        }
    }
    return ;
}
int check(int x){
    for(int i=1;i<=dd;i++){
        if(d[i].st<=a[x]&&a[x]<=d[i].en){
            return 1;
        }
    return 0;
    }
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        la[i]=w[a[i]];
        w[a[i]]=i;
        if(a[i]<a[i-1]){
            flag=0;
        }
    }/*
    for(int i=1;i<=n;i++){
        cout<<i<<" "<<la[i]<<endl;
    }
    cout<<"------------\n";*/
    if(flag==1){
        solveA();
        return 0;
    }
    int k;
    for(int i=1;i<=n;i++){
        k=2;
        memset(b,0,sizeof(b));
        b[1]=a[i];
        for(int j=i+1;j<=n;j++){
            if(la[j]<i ||check(la[j])){
                b[k]=a[j];
                k++;
            }
            else{
                d[dd].st=la[j]+1;
                d[dd].en=j;
                dd++;
                k=la[j]+1;
            }

        }/*
        for(int j=1;j<k;j++){
            cout<<j<<" "<<b[j]<<endl;
        }
        cout<<"------------\n";*/
        for(int j=1;j<k;j++){
            ans[b[j]]++;
        }
        if(i==n){
            for(int j=1;j<=m;j++){
                cout<<ans[j]<<" ";
            }
        }

    }
    return 0;
}
