#include<bits/stdc++.h>
using namespace std;
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
int a[99],c[99],b[99],d[99],n,m,e=0,k=0;
string b,t="",y="";
void op(int q){
    for(int i=q;i<n;i++){
        c[i]=a[i];
        for(int j=q;j<i;j++){
            if(a[i]==b[j]){
                for(int l=j;l<i;l++){
                    c[l]=0;
                }
            }
        }
    }
    for(int l=q;l<n;l++){
        for(int j=q;j<e;j++){
            if(a[i]==b[j]){
                d[j]++;
            }
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
        d[j]=0;
        for(int j=0;j<m;j++){
            if(a[i]!=b[j]){
                e++;
            }
        }
        if(e==m){
            b[k]=a[i];
            k++;
        }
        e=0;
    }
    k=0;
    for(int j=0;j<n;j++){
        op(n-j);
    }
    for(int j=0;j<m;j++){
        cout<<d[j];
    }
    return 0;
}
