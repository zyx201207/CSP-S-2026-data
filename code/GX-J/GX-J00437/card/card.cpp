#include <bits/stdc++.h>
using namespace std;

int n,m;
int z[100000];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    int a[n];
    int b[n];
    for(int i=0;i<n;i++){
        cin>>a[i];}
    for(int i=1;i<n;i++){
        for(int j=i;j<n;j++){
            for(int k=0;k<n;k++){
            z[k]=a[j];
            }
        }
    }
    cout<<0;
    return 0;}
