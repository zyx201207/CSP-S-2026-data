#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card1.in","r",stdin);
    freopen("card.out","w",stdout);
    int a[500000],b[500000]={0},n,m,x=0,y=0;
    cin>>n>>m;
    long long int c[m]={0};
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int z=0;z<n;z++){
    for(int i=0;i<n-y;i++){
        for(int j=0;j<n;j++){
            if(a[i]!=b[j]){
                b[x]=a[i];
            }
    }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<x;j++){
            if(i+1 == 1){
                c[i]++;

            }
    }
    }
    }
    for(int j=0;j<m;j++){
        if(c[j]==0){
            cout<<c[j];
            }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
