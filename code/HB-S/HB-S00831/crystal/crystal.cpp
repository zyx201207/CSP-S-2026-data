#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.in","r",stdin);
    int i=0,n,m,z=0;
    cin>>n>>m;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int s=0;s<m;s++){
        for(int j=0;j<n;j++){
            if(a[j]+a[j]==a[j+1]){
                z++;
                a[j]++;
            }else{
                a[j]++;
            }
        }
    }
    cout<<z;
    return 0;
}
