#include<bits/stdc++.h>
using namespace std;
int out[50002]={0};
int num[100002]={0};
int n,m;
void work(int stai){
    int hav[50002]={0};
    for(int i=stai;i<=n;i++){
        if(hav[num[i]]!=0){
            for(int j=hav[num[i]];j<i;j++){hav[num[j]]=0;}
        }
        hav[num[i]]=i;
    }
    for(int i=1;i<=m;i++){
        if(hav[i]!=0){out[i]++;}
    }
    return;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){cin>>num[i];}
    for(int i=1;i<=n;i++){work(i);}
    for(int i=1;i<=m;i++){cout<<out[i]<<' ';}
    return 0;
}
