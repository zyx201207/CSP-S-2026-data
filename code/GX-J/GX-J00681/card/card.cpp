#include<iostream>
using namespace std;
int a[500001],b[300001],c[300001];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<=m;i++)c[i]=-1;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(c[a[j]]!=-1){
                for(int k=c[a[j]];k<j;k++){
                    c[a[k]]=-1;
                }
            }
            c[a[j]]=j;
        }
        for(int j=1;j<=m;j++){
            if(c[j]!=-1){
                b[j]++;
            }
            c[j]=-1;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<b[i]<<" ";
    }
    return 0;
}
