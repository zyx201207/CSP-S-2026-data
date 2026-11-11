#include<bits/stdc++.h>
using namespace std;
int main(){
    //freopen("travel.in","r";stdin);
    //freopen("travel.out","w";stdout);
    int n;
    cin>>n;
    int m;
    cin>>m;
    int a[n+1];
    int p[m+1]=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(j=i;j<=n;j++){
            for(k=n;k>j;k--){
                if(a[k]==a[j]){
                    j=k;
                }
            }
            p[a[j]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<p[i]<<" ";
    }
    return 0;
}