#include<bits/stdc++.h>
using namespace std;
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
int n,m,nm=1;
int a[100086];
int q[100086];
int as[1005];
int fl=1;
int c(int x){
    int f=-1;
    for(int i=1;i<=n;i++){
        if(q[i]==x){
            f=i;
            break;
        }
    }
    return f;
}
void bfs(){
    for(int k=1;k<=n;k++){
        for(int i=fl;i<=n;i++){
            if(c(a[i])==-1){
                q[nm]=a[i];
                nm++;
            }
            else{
                nm=c(a[i])+1;
                for(int i1=c(a[i1])+1;i1<=n;i1++){
                    q[i1]=0;
                }
            }
        }
        for(int i=1;i<=n;i++){
            as[q[i]]++;
        }
        fl++;
        nm=1;
        int d=1;
        while(q[d]!=0){
            q[d]=0;
            d++;
        }
    }
    return ;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    bfs();
    for(int i=1;i<=m;i++){
        cout<<as[i];
    }
    return 0;
}
