#include<bits/stdc++.h>
using namespace std;
int f[100009],ans[100009];
int main(){
int n,m;
cin>>n>>m;
int a[n];
for(int i=0;i<n;i++)cin>>a[i];
for(int i=0;i<n;i++){
    for(int j=i;j<n;j++){
        if(f[a[j]]==1){
            for(int k=0;k<=30000;k++)f[k]=0;
        }
        f[a[j]]++;
    }
    for(int p=0;p<30000;p++)ans[f[p]]++;
}
for(int p=1;p<=m;p++)cout<<ans[p]<<" ";
return 0;
}