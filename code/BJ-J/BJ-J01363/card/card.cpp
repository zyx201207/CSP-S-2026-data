#include<iostream>
#include<cstdio>
using namespace std;
int stateeeeeee[300005];
int q01083[500005];
int q01075[300005];
//int ind[[[[[[[[[[[[[[[[[[[[[[[88888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888]]]]]]]]]]]]]]]]]]]]]]];(doge)
int ind[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.ans","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>q01083[i];
    }
    int indexxxxxxxxx=1;
    for(int j=1;j<=n;j++){
        for(int i=j;i<=n;i++){
            if(ind[q01083[i]]==0){
                ind[q01083[i]]=indexxxxxxxxx;
                q01075[indexxxxxxxxx]=q01083[i];
                indexxxxxxxxx++;
            } else {
                indexxxxxxxxx=ind[q01083[i]];
                for(int k=1;k<=m;k++){
                    if(ind[k]>indexxxxxxxxx) ind[k]=0;
                }
            }
        }
        for(int i=1;i<=m;i++){
            if(ind[i]!=0){
                stateeeeeee[i]++;
            }
        }
        for(int i=1;i<=m;i++){
            ind[i]=0;
        }
    }
    for(int i=1;i<=m;i++) cout<<stateeeeeee[i]<<' ';
    return 0;
}
